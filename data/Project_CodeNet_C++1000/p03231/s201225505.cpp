#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool f = 1;

    ll g = __gcd(m,n);
    ll l = m * n / g;

    map<ll,char> good;

    rep(i, n){
        good[(l/n)*i] = s[i];
    }
    rep(i, m) {
        if(good[(l/m)*i] == 0) continue;
        f &= (good[(l/m)*i] == t[i]);
    }

    if (f) cout << l << endl;
    else cout << -1 << endl;

    return 0;
}
