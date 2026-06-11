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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(whole(a));
    //reverse(whole(a));
    vector<P> b(m);
    rep(i, m) cin >> b[i].first >> b[i].second;
    auto comp = [](P a, P b) {
        return a.second > b.second;
    };
    sort(whole(b), comp);
    ll ans = 0;
    int id = 0;
    rep(i, n) {
        if (b[id].first==0) {
            id++;
        }
        if (a[i]<b[id].second) {
            ans += b[id].second;
            b[id].first--;
        }
        else {
            ans += a[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}
