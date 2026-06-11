#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;

#define out(a) cout << a << endl
#define out1(a) cout << a
#define in(a) cin >> a
#define in2(a, b) cin >> a >> b
#define in3(a, b, c) cin >> a >> b >> c
#define rep(i, N) for (ll i = 0; i < (ll)N; i++)
#define rep1(i, N) for (ll i = 1; i <= (ll)N; i++)
#define repi(i, j, N) for (ll j = (ll)i + 1; j < (ll)N; j++)
#define all(v) v.begin(), v.end()

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

constexpr int inf = 1e9;
constexpr ll linf = 1e18;
constexpr ll mod = 1e9 + 7;

void solve();

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}

void solve()
{
    int n;
    in(n);
    int a[n + 2];
    ll sum = 0;
    a[0] = 0;
    a[n + 1] = 0;
    rep1(i, n + 1)
    {
        in(a[i]);
        sum += abs(a[i] - a[i - 1]);
    }

    rep1(i, n)
    {
        int tmp = sum;
        tmp = tmp + abs(a[i + 1] - a[i - 1]) - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]);
        out(tmp);
    }
}