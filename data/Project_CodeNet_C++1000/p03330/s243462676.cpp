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
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c));
    vector<vector<int>> col(n, vector<int>(n));
    
    rep(i, c) rep(j, c) cin >> d[i][j];
    rep(i, n) rep(j, n) {
        cin >> col[i][j];
        col[i][j]--;
    }
    

    vector<vector<int>> num(c, vector<int>(3));
    rep(i, n) rep(j, n) {
        num[col[i][j]][(i+j)%3]++;
    }
    

    vector<vector<int>> diff(c, vector<int>(3));

    rep(i, c) rep(j, 3) {
        rep(k, c) {
            diff[i][j] += num[k][j] * d[k][i];
        }
    }

    int ans = INF;

    rep(i, c) rep(j, c) rep(k, c) {
        if (i==j || j==k || i==k) continue;
        chmin(ans, diff[i][0]+diff[j][1]+diff[k][2]);
    }
    
    cout << ans << endl;
    return 0;
}
