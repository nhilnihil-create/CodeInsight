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


int main(){
    int n;
    cin >> n;
    string ans = "Yes";
    int x = 0;
    int y = 0;
    int t = 0;
    
    rep(i, n) {
        int it, ix, iy;
        cin >> it >> ix >> iy;
        int d = abs(ix-x) + abs(iy-y);
        if (d<=it-t && (d%2)==((it-t)%2)) {
            t = it; x = ix; y = iy;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    
    
    cout << ans << endl;
    return 0;
}
