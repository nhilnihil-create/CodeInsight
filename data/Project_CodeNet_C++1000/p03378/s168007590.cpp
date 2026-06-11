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
    int n, m, x;
    cin >> n >> m >> x;

    int ans = 100000;
    vector<bool> z(n+1);
    rep(i, m) {
        int a;
        cin >> a;
        z[a] = true;
    }

    int v = x;
    int score = 0;
    while (v--) {
        if (z[v]) score++;
    }
    chmin(ans, score);
    v = x;
    score = 0;
    while (v++ && v<=n) {
        if (z[v]) score++;
    }
    chmin(ans, score);
    
    cout << ans << endl;
    return 0;
}
