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

ll f(ll i, ll x) {
    i++;
    ll p = 2*x;
    ll res = 0;
    res += (i - i%p)/2;
    res += max(0LL, i%p-x);
    return res;
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    //debug(f(7, 2));

    for (ll i=60; i>=0; i--) {
        ll now = 1LL<<i;
        ll big = f(b, now);
        ll small = f(a-1, now);
        if ((big-small)%2==1) {
            ans += now;
        }
    }
    
    cout << ans << endl;
    return 0;
}
