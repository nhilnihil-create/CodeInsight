#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    map<ll, ll> mp;
    vector<ll> sum(n+1);
    rep(i, n) {
        sum[i+1] = sum[i] + a[i];
    }
    rep(i, n+1) {
        mp[sum[i]%m]++;
    }
    for (auto m: mp) {
        ll v = m.second;
        ans += v*(v-1)/2;
    }
    
    cout << ans << endl;
    return 0;
}
