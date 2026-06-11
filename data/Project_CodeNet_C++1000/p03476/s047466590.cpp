#include <bits/stdc++.h>
using namespace std;

// エイリアス
using  ll = long signed long;
using ull = long unsigned long;
using  ld = long double;
using   P = pair<int, int>;
using llP = pair<ll, ll>;
using DoP = pair<double, double>;

// 汎用マクロ
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOREACH(i,q) for (auto &i : q)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
#define SZ(x) ((int)(x).size())
template <class T>inline bool chmin(T &a, const T b) {if (a > b) { a = b; return true;} return false;}
template <class T>inline bool chmax(T &a, const T b) {if (a < b) { a = b; return true;} return false;}
template <class T>inline void line_out(const vector<T> vec) {int n = SZ(vec); rep(i, n) { cout << vec[i]; if(i < n-1) cout << " ";}cout << endl;}
const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int di2[] = {1, 1, -1, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1};
const int dj2[] = {1, -1, 1, -1, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2, 2};
const int INF = 1 << 28;
const ll INF64 = 1ll << 55;
const int mod = 1000000007;
//const int mod = 998244353;


int main(){
  vector<int> prime(100001, true);
  prime[0] = prime[1] = false;
  for(ll i = 2; i <= 100000; ++i) {
    if(prime[i]) {
      for(ll j = i*i; j <= 100000; j += i) prime[j] = false;
    }
  }
  vector<int> vec(100001, 0);
  rep(i, 100001) {
    if(i%2==0) continue;

    if(prime[i] && prime[(i+1)/2]) ++vec[i];
  }
  rep(i, 100000) vec[i+1] += vec[i];
  int q; cin >> q;
  vector<int> ans;
  rep(i, q) {
    int l, r; cin >> l >> r;
    ans.push_back(vec[r] - vec[l-1]);
  }
  for(auto x : ans) cout << x << endl;
}