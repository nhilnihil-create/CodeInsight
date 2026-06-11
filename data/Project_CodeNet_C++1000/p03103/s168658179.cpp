#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<ll, ll>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    ll n, m;
    cin >> n >> m;
    vector<P> a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;
    ll ans = 0;
    sort(whole(a));
    rep(i, n) {
        if (a[i].second<=m) {
            m -= a[i].second;
            ans += a[i].first*a[i].second;
        }
        else {
            ans += a[i].first*m;
            m-=m;
        }
        if (m<=0) break;
    }
    
    cout << ans << endl;
    return 0;
}
