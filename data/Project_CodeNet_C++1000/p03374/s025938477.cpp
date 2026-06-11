#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;


int main()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> x(n), v(n);
    rep(i, 0, n)
        cin >> x[i] >> v[i];

    vector<ll> cumsum(n + 1), cumsum_rev(n + 1);
    cumsum[0] = cumsum_rev[0] = 0;
    rep(i, 0, n)
    {
        cumsum[i + 1] = cumsum[i] + v[i];
        cumsum_rev[i + 1] = cumsum_rev[i] + v[n - i - 1];
    }

    vector<ll> back(n + 1), back_rev(n + 1);
    back[0] = back_rev[0] = 0;
    rep(i, 0, n) 
    {
        back[i + 1] = max(back[i], cumsum[i + 1] - x[i] * 2);
        back_rev[i + 1] = max(back_rev[i], cumsum_rev[i + 1] - (c - x[n - i - 1]) * 2);
    }

    ll ans;
    ans = max(cumsum[n] - x[n - 1], cumsum_rev[n] - (c - x[0]));
    ans = max(0LL, ans);
    rep(i, 0, n - 1)
    {
        ll cand1 = cumsum[i + 1] + back_rev[n - i - 1] - x[i];
        ll cand2 = cumsum_rev[i + 1] + back[n - i - 1] - (c - x[n - 1 - i]);
        ans = max(ans, cand1);
        ans = max(ans, cand2);
    }
    cout << ans << endl;
    return 0;
}