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
const int INF = 1001001001;


int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> z(4);
    z[1] = a; z[2] = b; z[3] = c;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    int ans = INF;
    rep(i, 1<<(2*n)) {
        vector<int> v(n);
        rep(j, n) {
            v[j] = (i>>(2*j))&3;
        }
        vector<int> x[4];
        rep(j, n) {
            x[v[j]].push_back(l[j]);
        }
        bool ok = true;
        for (int j=1; j<=3; j++) {
            if (x[j].size()==0) ok = false;
        }
        if (!ok) continue;
        int mp = 0;
        for (int j=1; j<=3; j++) {
            int res = 10*(x[j].size()-1);
            int sum = 0;
            for (int y: x[j]) sum += y;
            res += abs(sum-z[j]);
            mp += res;
        }
        ans = min(ans, mp);
    }
    
    cout << ans << endl;
    return 0;
}
