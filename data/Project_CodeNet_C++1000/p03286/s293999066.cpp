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
    ll n;
    cin >> n;

    string ans = "";
    rep(i, 60) {
        ll now = 1LL<<i;
        if (i%2==1) now *= -1;
        if (abs(n)%abs(now*2)) {
            ans += '1';
            n -= now;
        }
        else ans += '0';
        if (n==0) break;
    }
    reverse(whole(ans));
    
    cout << ans << endl;
    return 0;
}
