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
    vector<int> a(n);
    int x = -1;
    rep(i, n) {
        cin >> a[i];
        if (a[i]==1) x = i;
    }
    int ans = 1001001001;
    rep(i, k) {
        int l = max(x-i, 0);
        int r = max(n-x-1-(k-1-i), 0);
        int res = 1;
        if (l>0) res += (l-1)/(k-1)+1;
        if (r>0) res += (r-1)/(k-1)+1;
        
        chmin(ans, res);
    }
    
    
    cout << ans << endl;
    return 0;
}
