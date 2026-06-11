#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;

int main(){
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a + 2), t(b + 2);
    for (int i = 1; i < a+1; i++)
    {
        cin >> s[i];
    }
    s[a + 1] = INF;
    s[0] = -INF;
    for (int i = 1; i < b + 1; i++)
    {
        cin >> t[i];
    }
    t[b + 1] = INF;
    t[0] = -INF;
    for (int k = 0; k < q; k++)
    {
        ll x;
        cin >> x;
        auto i = lower_bound(s.begin(), s.end(), x);
        auto j = lower_bound(t.begin(), t.end(), x);
        ll S[] = {*i, *(i - 1)};
        ll T[] = {*j, *(j - 1)};
        ll ans = INF;
        for (ll s : S)
        {
            for(ll t:T)
            {
                ll d1, d2;
                d1 = abs(x - s) + abs(s - t);
                d2 = abs(x - t) + abs(t - s);
                ans = min(ans, min(d1, d2));
            }
        }
        cout << ans << endl;
    }
}