#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k==0) {
        cout << n*n << endl;
        return 0;
    }
    for (ll i=k+1; i<=n; i++) {
        ll v = n/i;
        ll now = v*(i-k);
        v = n%i;
        if (v>0) {
            if (k==0) now += v;
            else now += max(0LL, v-k+1);
        }
        ans += now;
        //cout << now << endl;
    }
    
    
    
    
    cout << ans << endl;
    return 0;
}
