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
    ll n;
    cin >> n;
    vector<ll>a, b, c;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }

     for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        b.push_back(x);
    }

     for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        c.push_back(x);
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for (ll i = 0; i < n; i++) {
        ll p = b[i];
        auto aa = upper_bound(a.begin(), a.end(), p - 1);
        auto cc = lower_bound(c.begin(), c.end(), p + 1);

        ll k = c.end() - cc;
        ll kk = aa - a.begin();
        ans += (k * kk);
    }

    cout << ans << endl;
    return 0;
}
