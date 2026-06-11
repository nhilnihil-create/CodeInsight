#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}


ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}

int main() {
  int T; cin >> T;

  rep(t, T) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b || b > d) {
      cout << "No" << endl;
      continue;
    }

    ll p = gcd(b, d);
    ll k1 = (a-b)/p + 1;
    ll k2 = (a-c+p-1)/p - 1;
    if (k1 > k2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
