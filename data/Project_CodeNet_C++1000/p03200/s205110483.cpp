#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  string S;
  cin >> S;

  // BWの並びをWBに変える操作は何回できるか

  // Bから見て右にある、次のBまでのWの個数分、操作できる
  // 入れ替えるとWは左に移るため、操作できる回数も変わる
  // 一番右端から確認する

  // 操作がすべて反転
  reverse(S.begin(), S.end());

  ll ans = 0;
  ll count = 0; // Wの個数
  for (int i = 0; i < S.length(); ++i) {
    if (S[i] == 'W') {
      count++;
    } else {
      ans += count;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}