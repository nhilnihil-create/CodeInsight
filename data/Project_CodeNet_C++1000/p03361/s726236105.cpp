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


int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    string ans = "Yes";
    rep(i, h) rep(j, w) {
        if (s[i][j]=='.') continue;
        bool ok = false;
        rep(k, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if (s[ni][nj]=='#') ok = true;
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    
    cout << ans << endl;
    return 0;
}
