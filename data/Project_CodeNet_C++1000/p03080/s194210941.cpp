// [[ABC134C] Exception Handling] https://www.luogu.com.cn/problem/AT4843
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int rcnt = 0, bcnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R')
      rcnt++;
    else
      bcnt++;
  }

  cout << (rcnt > bcnt ? "Yes\n" : "No\n") << endl;
  return 0;
}
