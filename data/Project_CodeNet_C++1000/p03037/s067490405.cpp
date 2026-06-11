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
    ll n, m;
    cin >> n >> m;
    ll mx = 1,mn = n;

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        mx = max(mx, a);
        mn = min(mn, b);
    }
    ll z = 0;
    cout << max(z, ((mn - mx) + 1)) << endl;
    return 0;
}
