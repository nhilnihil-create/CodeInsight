#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
vll yakusuu;
void div(ll N)
{
    for (ll i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            yakusuu.push_back(i);
            if (i * i != N)
                yakusuu.push_back(N / i);
        }
    }
}
int main()
{
    ll N, ans = 0;
    cin >> N;
    div(N);
    for (auto i : yakusuu)
    {
        ll m = N / i - 1;
        if (N / (m + 1) < m)
            ans += m;
    }
    cout << ans;
    return 0;
}