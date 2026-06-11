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
   ll n, x;
   cin >> n;
   vector<ll>v;
   for (ll i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
   }
   ll ans = 0;

   for (ll i = 0; i < n - 1; i++) {
    if(v[i] > v[i+1]) {
        ans += v[i] - v[i+1];
    }
   }
   ans += v[n-1];
   cout << ans << endl;
    return 0;
}


