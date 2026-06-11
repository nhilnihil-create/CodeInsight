#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// const int MAX = 1010;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> cum(n + 1);
    for (int i = 0; i < n; i++)
    {
        cum[i + 1] = cum[i] + a[i];
    }
    map<ll, ll> mp;
    for (auto c : cum)
    {
        mp[c]++;
    }
    ll ans = 0;
    for (auto m : mp)
    {
        if (m.second >= 2)
        {
            ans += m.second * (m.second - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}