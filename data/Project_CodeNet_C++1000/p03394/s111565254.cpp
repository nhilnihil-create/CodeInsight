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


int main() {
  int n; cin >> n;

  if (n == 3) { cout << "2 5 63" << endl; return 0; }
  if (n == 4) { cout << "2 3 4 9" << endl; return 0; }
  if (n == 5) { cout << "2 3 4 6 9" << endl; return 0; }

  int k = min(n/6, 2500);
  rep(i, k) {
    cout << (12*i + 2) << " ";
    cout << (12*i + 3) << " ";
    cout << (12*i + 4) << " ";
    cout << (12*i + 8) << " ";
    cout << (12*i + 9) << " ";
    cout << (12*i + 10) << " ";
  }
  rep(i, n-6*k) {
    cout << (6*i + 6) << " ";
  }
  cout << endl;
  return 0;
}
