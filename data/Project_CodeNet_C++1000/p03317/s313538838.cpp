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

    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll i = 0, c = 0;
    while(i < n - 1) {
        i += k - 1;
        c++;
    }
    cout << c << endl;
    return 0;
}
