#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;


int main(){
    int n, t;
    cin >> n >> t;
    int ans = mod;
    rep(i, n) {
        int c, x;
        cin >> c >> x;
        if (x>t) continue;
        ans = min(ans, c);
    }
    if (ans==mod) {
        cout << "TLE" << endl;
        return 0;
    }
    
    
    
    cout << ans << endl;
    return 0;
}
