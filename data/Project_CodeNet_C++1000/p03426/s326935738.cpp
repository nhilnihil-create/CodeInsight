#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<char>> g;
int main(){
    ll h, w, d; cin >> h >> w >> d;
    map<ll, pair<ll, ll>> mp;
    rep(i, h)   rep(j, w){
        ll x;   cin >> x;
        mp[x] = {i+1, j+1};
    }
    vector<ll> g(h*w+1, 0);
    rep(i, h*w+1){
        if(i<d) continue;
        g[i] = g[i-d];
        g[i] += abs(mp[i-d].first-mp[i].first)+abs(mp[i-d].second-mp[i].second);
    }
    ll q;   cin >> q;
    rep(times, q){
        
        ll from, to;    cin >> from >> to;
        cout << g[to] - g[from] << endl;
    }
}
