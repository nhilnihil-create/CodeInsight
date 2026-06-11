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
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

bool f(P a, P b) {
    return a.first<b.first && a.second<b.second;
}


int main(){
    int n;
    cin >> n;
    vector<P> r(n);
    vector<P> b(n);
    rep(i, n) cin >> r[i].first >> r[i].second;
    rep(i, n) cin >> b[i].first >> b[i].second;
    sort(whole(r));
    sort(whole(b));
    vector<bool> used(n);
    
    int ans = 0;
    rep(i, n) {//b
        int id = -1;
        int maxy = -1;
        rep(j, n) {//r
            if (used[j]) continue;
            if (!f(r[j], b[i])) continue;
            if (r[j].second>maxy) {
                id = j;
                maxy = r[j].second;
            }
        }
        if (id != -1) {
            ans++;
            used[id] = true;
        }
    }
    
    
    cout << ans << endl;
    return 0;
}
