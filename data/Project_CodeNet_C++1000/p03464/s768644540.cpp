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

ll a[100010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];

    bool flag = true;

    if (a[n-1] != 2) flag = false;

    ll mx = 3, mn = 2;

    rrep(i, n - 1){
        ll p = a[i];
        ll nmx = mx / p * p;
        ll nmn = (mn + p - 1) / p * p;
        // cout << nmx << " " << nmn << endl;
        if (nmn > mx || nmx < mn) {
            flag = false;
            break;
        }
        mx = nmx + p - 1;
        mn = nmn;
    }

    if (flag) cout << mn << " " << mx << endl;
    else cout << -1 << endl;

    return 0;
}
