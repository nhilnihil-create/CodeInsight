#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

const int MX = 200005;
vector<P> tim[30];

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> v(MX);
    rep(i, n) {
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        s *= 2; t *= 2;
        tim[c].emplace_back(s-1, t);
    }
    
    rep(i, 30) {
        if (tim[i].size()==0) continue;
        sort(whole(tim[i]));
        rep(j, tim[i].size()-1) {
            if (tim[i][j].second>tim[i][j+1].first) {
                tim[i][j+1].first = tim[i][j].first;
                tim[i][j] = P(MX-1, MX-1);
            }
        }
        for (auto p: tim[i]) {
            v[p.first]++;
            v[p.second]--;
        }
    }
    
    
    int ans = 0;
    int now = 0;
    rep(i, MX) {
        now += v[i];
        chmax(ans, now);
    }
    
    cout << ans << endl;
    return 0;
}
