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
    vector<int> a(5);
    rep(i, 5) cin >> a[i];
    int ans = 100000;
    do {
        int m = 0;
        rep(i, 5) {
            m += a[i];
            if (i==4) continue;
            if (m%10!=0) m += (10-m%10);
        }
        ans = min(ans, m);
    } while (next_permutation(a.begin(), a.end()));
    
    
    
    cout << ans << endl;
    return 0;
}
