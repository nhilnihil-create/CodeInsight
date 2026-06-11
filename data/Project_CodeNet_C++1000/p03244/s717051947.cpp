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

ll mypow(ll a, ll b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return a * mypow(a, b - 1);
    }
}

signed main()
{
    int n;
    cin >> n;
    map<ll, ll> m1;
    map<ll, ll> m2;
    rep(i, n)
    {
        int v;
        cin >> v;
        if (i % 2 == 0)
        {
            m1[v]++;
        }
        else
        {
            m2[v]++;
        }
    }
    pair<ll, ll> m1_1st = {-1, 0};
    pair<ll, ll> m1_2nd;
    pair<ll, ll> m2_1st = {-1, 0};
    pair<ll, ll> m2_2nd;
    for (auto &i : m1)
    {
        if (i.second >= m1_1st.second)
        {
            m1_2nd = m1_1st;
            m1_1st = i;
        }
        else if (i.second >= m1_2nd.second)
        {
            m1_2nd = i;
        }
    }
    for (auto &i : m2)
    {
        if (i.second >= m2_1st.second)
        {
            m2_2nd = m2_1st;
            m2_1st = i;
        }
        else if (i.second >= m2_2nd.second)
        {
            m2_2nd = i;
        }
    }
    // cout<<m1_1st.first<<" "<<m1_1st.second<<" "<<m1_2nd.first<<" "<<m1_2nd.second<<" "<<
    // m2_1st.first<<" "<<m2_1st.second<<" "<<m2_2nd.first<<" "<<m2_2nd.second<<endl;
    if (m1_1st.first != m2_1st.first)
    {
        cout << n - m1_1st.second - m2_1st.second << endl;
    }
    else
    {
        ll ans = min(n - m1_1st.second - m2_2nd.second, n - m1_2nd.second - m2_1st.second);
        cout << ans << endl;
    }
 
    return 0;
}