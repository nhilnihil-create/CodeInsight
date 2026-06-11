#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


map<ll, ll> prime_factor(ll n) {
    map<ll, ll> ret;
    for (ll j = 2; j <= n; j++){
        ll J = j;
        for(ll i = 2; i * i <= j; i++) {
            while(J % i == 0) {
                ret[i]++;
                J /= i;
            }
        }
        if(J != 1) ret[J]++;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    map<ll, ll> tmp = prime_factor(n);
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for(auto p : tmp) {
        // cout << p.first << " " << p.second << endl;
        if (p.second >= 2) a++;
        if (p.second >= 4) b++;
        if (p.second >= 14) c++;
        if (p.second >= 24) d++;
        if (p.second >= 74) e++;
    }

    // cout << a << " " << b << endl;
    // cout << b * (b - 1) / 2 * (a - 2) << endl;

    ll ans = 0;
    ans += max(b * (b - 1) / 2 * (a - 2), 0);
    ans += max(d * (a - 1), 0);
    ans += max(c * (b - 1), 0);
    ans += e;

    cout << ans << endl;
    return 0;
}