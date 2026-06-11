#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
bool Check(vector<int> a, int m) {
  int n = a.size();
  vector<pair<int, int>> rle;
 
  for (int i = 0; i < n; ++i) {
    int diff = a[i] - (i > 0 ? a[i - 1] : 0);
    if (diff > 0) {
      rle.push_back({0, diff});
      continue;
    }
 
    while (diff < 0) {
      int take = min(-diff, rle.back().second);
      diff += take;
      rle.back().second -= take;
      if (rle.back().second == 0) {
        rle.pop_back();
      }
    }
 
    int numDigits = 0;

    while (!rle.empty() && rle.back().first == m - 1) {
      numDigits += rle.back().second;
      rle.pop_back();
    }
    if (rle.empty()) return false;
 
    int curValue = rle.back().first;
    int curLen = rle.back().second;
    rle.pop_back();

    if (curLen > 1) {
      rle.push_back({curValue, curLen - 1});
    }
    rle.push_back({curValue + 1, 1});
 
    if (numDigits > 0) {
      rle.push_back({0, numDigits});
    }
 
  }
  return true;
}
 
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
 
  int l = 0; int r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (Check(a, m)) {
      r = m;
    } else {
      l = m;
    }
  }
  int result = r;
  cout << result << endl;
 
  return 0;
}

