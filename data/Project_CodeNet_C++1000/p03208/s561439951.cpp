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
    ll k, n, x;
    cin >> n >> k;
    vector<ll>v, u;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll ans = INT_MAX;
    for (ll i = 0; i < n - k + 1; i++) {
    ans = min(ans, (v[i + k - 1] - v[i]));
   }
   cout << ans << endl;
   return 0;

}

