//vec[i]の範囲外エラー表示
#define _GLIBCXX_DEBUG
//includeとusing
#include <bits/stdc++.h>
using namespace std;
//型名省略
typedef long long ll;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<string> vs;
//定数
const ll INF = 1e9;
const ll MOD = 1e9+7;
//マクロ
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define all(A) A.begin(), A.end()
//入力
ll llin() {ll x; cin >> x; return x;}
string stin() {string s; cin >> s; return s;}
vl vlin(ll n) {vl a(n); rep(i,n){cin >> a[i];} return a;}
//正誤判定
void Yes(bool ans){cout << (ans? "Yes" : "No") << endl;}
void YES(bool ans){cout << (ans? "YES" : "NO") << endl;}


//main関数
int main() {
  ll n = llin();
  vl lucas(n + 1);
  lucas[0] = 2; lucas[1] = 1;

  xrep(i,2,n + 1){
    lucas[i] = lucas[i - 1] + lucas[i - 2];
  }

  cout << lucas[n] << endl;
}

