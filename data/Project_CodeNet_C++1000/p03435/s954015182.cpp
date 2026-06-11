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

int c[3][3];

int main(){
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    string ans = "Yes";
    if (c[0][0]-c[0][1]!=c[1][0]-c[1][1]) ans = "No";
    if (c[1][0]-c[1][1]!=c[2][0]-c[2][1]) ans = "No";
    if (c[0][0]-c[1][0]!=c[0][1]-c[1][1]) ans = "No";
    if (c[0][1]-c[1][1]!=c[0][2]-c[1][2]) ans = "No";
    vector<int> v(3);
    rep(i, 3) rep(j, 3) {
        v[(i+j)%3] += c[i][j];
    }
    if (v[0]!=v[1]) ans = "No";
    if (v[1]!=v[2]) ans = "No";

    
    
    cout << ans << endl;
    return 0;
}
