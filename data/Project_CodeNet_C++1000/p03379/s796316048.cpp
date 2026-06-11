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
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> y = x;
    sort(whole(y));
    int z1 = y[n/2-1];
    int z2 = y[n/2];
    rep(i, n) {
        int ans = 0;
        if (x[i]<=z1) ans = z2;
        else ans = z1;
        cout << ans << endl;
    }
    
    return 0;
}
