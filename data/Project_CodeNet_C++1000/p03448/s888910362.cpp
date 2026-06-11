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
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    x /= 50;
    int ans = 0;
    rep(i, a+1) rep(j, b+1) rep(k, c+1) {
        int sum = 10*i + 2*j + k;
        if (sum==x) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
