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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    

    int ans = 0;

    
    for (int l=0; l<=k; l++) {
        for (int r=0; r<=k-l; r++) {
            if (l+r>n) continue;
            int x = k-l-r;
            int score = 0;
            vector<int> now;
            rep(i, l) {
                score += v[i];
                now.push_back(v[i]);
            }
            rep(i, r) {
                score += v[n-1-i];
                now.push_back(v[n-1-i]);
            }
            sort(whole(now));
            auto it = lower_bound(whole(now), 0);
            int numit = it - now.begin();
            x = min(x, numit);
            rep(i, x) {
                score -= now[i];
            }
            chmax(ans, score);
        }
    }
    
    
    cout << ans << endl;
    return 0;
}
