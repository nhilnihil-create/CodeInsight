#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

ll mod = 1000000007;


signed main()
{
    int n;
    string s;
    cin>>n>>s;
    vector<ll> a(26);
    rep(i,n){
        a[s[i] - 'a']++;
    }
    ll ans = 1;
    rep(i, 26)
    {
        ans = ans * (a[i] + 1) % mod;
    }
    cout << ans - 1 << endl;
    return 0;
}