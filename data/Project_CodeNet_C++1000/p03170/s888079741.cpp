#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<bool> dp;
vector<int> a;
int n, k;


int main(){
  
  cin >> n >> k;
  a.resize(n+1);
  rep(i, n) cin >> a[i+1];
  dp.resize(k+1);
  rep2(i, 1, k+1){
    rep2(j, 1, n+1) {
      if(i - a[j] >= 0 && dp[i-a[j]] == 0)dp[i] = 1;
    }
  }
  if(dp[k] == 0) cout << "Second" << endl;
  else cout << "First" << endl;
  
}