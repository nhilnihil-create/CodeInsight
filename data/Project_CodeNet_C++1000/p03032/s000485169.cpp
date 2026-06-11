#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

template <typename T>

void view(const std::vector<T> &v)
{
#ifndef ONLINE_JUDGE
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#endif
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv)
{
    for (const auto &v : vv)
    {
        view(v);
    }
}
#pragma endregion

int main()
{
    int n, k;
    cin >> n >> k;
    vint a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    vll s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];

    ll ans = 0;
    rep(i, k + 1)
    {
        if (i > n)
            break;

        ll left = s[i];

        rep(j, k - i + 1)
        {
            if (i + j > n)
                break;
            ll l = k - i - j;
            if (l < 0)
                continue;

            ll right = s[n] - s[n - j];

            multiset<ll> st;
            rep(x, i) st.emplace(a[x]);
            rep(x, j) st.emplace(a[n - 1 - x]);
            ll now = left + right;
            while (st.size() && l)
            {
                ll x = *(st.begin());
                if (x >= 0)
                    break;
                l--;
                st.erase(x);
                now -= x;
            }

            // printf("%d %d %d: %ld %ld, ", i, j, l, left, right);
            // cout << now << endl;
            ans = max(now, ans);
        }
    }

    cout << ans << endl;

    return 0;
}