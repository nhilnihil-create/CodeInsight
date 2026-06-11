#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

ll inf = 1000000000000000;
vector<vector<ll>> dp;
int n;
vector<ll> a,s;

ll rec(int l = 0, int r = n) {
  if ((r - l) <= 1) return 0;
  if ((r - l) == 2) {
    return a[l] + a[l+1];
  }

  if (dp[l][r] != inf) return dp[l][r];
  for (int i = l+1; i <= r-1; i++) {
    chmin(dp[l][r], rec(l,i) + rec(i,r) + s[r] - s[l]);
  }

  return dp[l][r];
}

int main() {
  cin >> n;
  a.resize(n);
  rep(i,0,n) cin >> a[i];
  s.resize(n+1);
  rep(i,0,n) {
    s[i+1] = s[i] + a[i];
  }
  dp.assign(n+2,vector<ll>(n+2,inf));
  cout << rec() << endl;
  return 0;
}
