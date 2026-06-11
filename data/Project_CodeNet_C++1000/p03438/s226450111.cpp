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

ll a[10010], b[10010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll cnt = 0;
    rep(i, n) cnt += (b[i] - a[i]);
    if (cnt < 0) {
        cout << "No" << endl;
        return 0;
    }

    ll c = 0, d = 0;
    rep(i, n){
        if (a[i] < b[i]) c += (b[i] - a[i] + 1) / 2;
        else d += (a[i] - b[i]);
    }

    if (max(c, d) <= cnt) cout << "Yes" << endl;
    else cout << "No" << endl;   

    return 0;
}
