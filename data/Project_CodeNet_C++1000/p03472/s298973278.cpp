#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll maxa = 0; //aの最大値
    rep(i, n) maxa = max(maxa, a[i]);

    ll cnt = 0;  //maxaより大きいbの個数
    ll sumb = 0; //maxaより大きいbの合計を格納

    sort(b.begin(), b.end(), greater<ll>());
    rep(i, n)
    {
        if (b[i] > maxa)
        {
            cnt++;
            sumb += b[i];
            if (sumb >= h)
            {
                cout << cnt << endl;
                return 0;
            }
        }
    }

    ll ans = cnt + (h - sumb + (maxa - 1)) / maxa;
    cout << ans << endl;
}