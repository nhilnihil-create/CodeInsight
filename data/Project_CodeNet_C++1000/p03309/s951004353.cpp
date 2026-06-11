#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[i] = (x - i);
    }
    sort(a+1, a+n+1);
    ll p = a[(n+1)/2];
    ll x = 0;

    for (ll i = 1; i <= n; i++) {
        x += abs(a[i] - p);
    }

    cout << x << endl;
    return 0;
}
