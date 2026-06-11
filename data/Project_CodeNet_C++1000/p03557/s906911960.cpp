#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];    
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(ALL(a));    
    sort(ALL(b));
    sort(ALL(c));

    vector<ll> d(n);
    rep(i, n){
        d[i] = (ll)(c.size() - (upper_bound(ALL(c), b[i]) - c.begin()));
    }

    for(int i=n-2; i>=0; i--) d[i] += d[i+1];

    ll ans = 0;
    rep(i, n){
        int t = upper_bound(ALL(b), a[i]) - b.begin();
        if(t<n) ans += (ll)d[t];
    }
    cout << ans << endl;
    
  	return 0;
}
