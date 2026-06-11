#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    ll n, k; cin >> n >> k;
    ll ans = 0;
    for(int b = 1; b <= n; b++){
        ans += max((b - k), 0LL) * (n / b) + max(n % b - k + 1, 0LL);
    }
    if(k == 0) ans = n * n;
    cout << ans << endl;
}
