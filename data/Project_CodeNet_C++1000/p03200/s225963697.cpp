#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  // すべてのWについて、それより左にあるBの数を数えて
  // 全部足した数が、求める値。
  long long n = 0;
  long long r = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B') {
      n++;
    } else {
      r += n;
    }
  }

  cout << r << endl;
  return 0;
}