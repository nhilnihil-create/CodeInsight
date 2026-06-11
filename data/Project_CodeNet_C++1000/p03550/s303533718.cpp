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

ll a[3000];

int main(){
    ll n, z, w;
    cin >> n >> z >> w;
    rep(i, n) cin >> a[i];
    if (n == 1) cout << abs(a[0]-w) << endl;
    else cout << max(abs(a[n-1]-w), abs(a[n-2]-a[n-1])) << endl;

    return 0;
}
