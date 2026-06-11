#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    ll min_val = 1e10;
    ll cnt_minus = 0;
    rep(i, n)
    {
        cin >> a[i];
        ans += abs(a[i]);
        min_val = min(min_val, abs(a[i]));
        if (a[i] < 0)
            cnt_minus++;
    }
    if (cnt_minus % 2 == 1)
        cout << ans - min_val * 2 << endl;
    else
        cout << ans << endl;
    return 0;
}