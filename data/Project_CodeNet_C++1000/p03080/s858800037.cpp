#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n;
  cin >> s;
  int red = 0;
  int blue = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') red++; else blue++;
  }
  string result = (red > blue) ? "Yes" : "No";
  cout << result << endl;
  return 0;
}
