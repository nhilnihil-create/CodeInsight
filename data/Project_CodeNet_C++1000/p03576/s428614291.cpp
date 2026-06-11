#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (ll i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<ll, ll>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const ll INF = 4E+18;


int main(){
    int n, k;
    cin >> n >> k;
    vector<P> v(n);
    rep(i, n) cin >> v[i].first >> v[i].second;
    auto comp = [](P a, P b) {
        return a.second < b.second;
    };
    sort(whole(v), comp);

    ll ans = INF;
    rep(i, n) rep(j, n) {
        if (j-i<k-1) continue;
        vector<P> tmp;
        for (int l=i; l<=j; l++) {
            tmp.push_back(v[l]);
        }
        sort(whole(tmp));
        ll dy = v[j].second - v[i].second;
        int ii = 0;
        int jj = k-1;
        while (jj<tmp.size()) {
            ll dx = tmp[jj].first - tmp[ii].first;
            chmin(ans, dx*dy);
            ii++; jj++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
