#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 2e5;

int x[MAXN + 1];
ll sp[MAXN + 1];;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, X;
    ios::sync_with_stdio(false);
    cin >> n >> X;
    for(i = 1; i <= n; i++) {
        cin >> x[i];
        sp[i] = sp[i - 1] + x[i];
    }
    ll ans = INF;
    for(int k = 1; k <= n; k++) {
        ll cur = (sp[n] - sp[max(0, n - 2 * k)]) * 5LL;
        int coef = 7;
        for(i = n - 2 * k; i >= 0; i -= k) {
            ll val = 1LL * coef * (sp[i] - sp[max(0, i - k)]);
            if(INF - cur <= val) {
                cur = INF;
                break;
            }
            cur += val;
            coef += 2;
        }
        if(INF - cur >= 1LL * X * k) {
            cur += 1LL * X * k;
            ans = min(ans, cur);
        }
    }
    cout << ans + 1LL * n * X;
    //cin.close();
    //cout.close();
    return 0;
}
