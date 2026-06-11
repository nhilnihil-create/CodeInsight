#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<int> ans;
  if(n == 0) {
    cout << 0;
  } else if(n > 0) {
    while(n > 0) {
      if(n % 4 == 0) {
        ans.push_back(0);
        ans.push_back(0);
      } else if(n % 4 == 1) {
        ans.push_back(1);
        ans.push_back(0);
      } else if(n % 4 == 2) {
        ans.push_back(0);
        ans.push_back(1);
        n += 2;
      } else if(n % 4 == 3) {
        ans.push_back(1);
        ans.push_back(1);
        n++;
      }
      n /= 4;
    }
    if(*ans.rbegin() == 0) {
      ans.erase(ans.end() - 1);
    }
  } else {
    n *= -1;
    while(n > 0) {
      if(n % 4 == 0) {
        ans.push_back(0);
        ans.push_back(0);
      } else if(n % 4 == 1) {
        ans.push_back(1);
        ans.push_back(1);
      } else if(n % 4 == 2) {
        ans.push_back(0);
        ans.push_back(1);
      } else if(n % 4 == 3) {
        ans.push_back(1);
        ans.push_back(0);
        n++;
      }
      n /= 4;
    }
  }
  reverse(ans.begin(), ans.end());
  for(const auto &p : ans) {
    cout << p;
  }
  cout << '\n';
  return 0;
}