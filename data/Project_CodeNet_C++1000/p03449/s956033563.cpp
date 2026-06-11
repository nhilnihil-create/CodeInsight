#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;
    ll n, x;
    cin >> n;
    vector<ll>v(n);
    vector<ll>u(n);
     for (ll i = 0; i < n; i++) {
        cin >> x;
        v[i] = x;
    }
    for (ll i = 0; i < n; i++) {
        cin >> x;
        u[i] = x;
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        ll s = 0;
        for (ll j = 0; j <= i; j++) {
            s += v[j];
        }
        for (ll j = i; j < n; j++) {
            s += u[j];
        }
        ans = max(ans , s);
    }

    cout << ans << endl;
    return 0;
}
