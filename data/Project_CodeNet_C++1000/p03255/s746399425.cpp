#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long double ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, X;
    cin >> n >> X;
    vi x(n), pre(n+1,0);
    rep(i,0,n) cin>>x[i];
    rep(i,0,n) pre[i+1] = x[i] + pre[i];
    ll best = 1/.0;
    rep(k,1,n+1) {
      ll cost = n*X + X*k;
      ll r = n;
      for(int s = 0; r; ++s) {
        ll l = max(ll(0),r-k);
        ll coeff = s ? 2*s+3 : 5;
        cost += (pre[r] - pre[l])*coeff;
        r = l;
      }
      //cerr << k << " " << cur << endl;
      best = min(best, cost);
    }
    cout << ((long long)best) << endl;
    return 0;
}
