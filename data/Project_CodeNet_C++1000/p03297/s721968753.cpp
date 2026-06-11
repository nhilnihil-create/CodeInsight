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

int main(){
    int t;
    cin >> t;
    rep(i, t){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < b || d < b) {
            cout << "No" << endl;
            continue;
        }
        if (c >= b - 1) {
            cout << "Yes" << endl;
            continue;
        }
        ll g = __gcd(b, d);
        if (b + a%g - g > c) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
