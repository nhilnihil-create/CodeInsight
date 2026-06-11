#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

//コンパイラ最適化
#pragma GCC optimize("Ofast")

/*

 */
//マクロ
// forループ
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
// Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
// FORAは範囲for文(使いにくかったら消す)
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)
#define FORA(i, I) for (const auto &i : I)
// xにはvectorなどのコンテナ
#define ALL(x) x.begin(), x.end()
#define SIZE(x) ll(x.size())
#define SORT(x) sort(x.begin(), x.end())
//定数
#define INF 1000000000000  // 10^12:∞
#define MOD 1000000007     // 10^9+7:合同式の法
#define MAXR 100000        // 10^5:配列の最大のrange
//略記
#define PB push_back  //挿入
#define MP make_pair  // pairのコンストラクタ
#define F first       // pairの一つ目の要素
#define S second      // pairの二つ目の要素

typedef long long ll;
using namespace std;
int stringcount(string s, char c) { return count(s.cbegin(), s.cend(), c); }
int uppercount(string s) {
  int cnt = 0;
  REP(i, s.length()) {
    if (isupper(s[i])) cnt++;
  }
  return cnt;
}
int main() {
  string S;
  cin >> S;
  bool flg = false;
  if (S[0] == 'A' && stringcount(S.substr(2, S.length() - 3), 'C') == 1 &&
      uppercount(S) == 2) {
    flg = true;
  }
  if (flg)
    cout << "AC";
  else
    cout << "WA";
  return 0;
}