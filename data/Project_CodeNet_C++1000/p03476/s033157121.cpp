#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chmax(T &u, const T z)
{
    if (u < z)
    {
        u = z;
        return true;
    }
    else
        return false;
}
template <typename T>
bool chmin(T &u, const T z)
{
    if (u > z)
    {
        u = z;
        return true;
    }
    else
        return false;
}
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
bool is_prime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int a[100010];
int kazu[100010];
int main()
{
    int q;
    cin >> q;
    for (int i = 2; i <= 100000; i++)
    {
        if (is_prime(i) == true && is_prime((i + 1) / 2) == true)
        {
            a[i] = 1;
        }
    }
    rep(i, 100001)
    {
        if (i == 0)
            kazu[i] = a[i];
        else
            kazu[i] = a[i] + kazu[i - 1];
    }
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        int ans = kazu[r] - kazu[l - 1];
        cout << ans << endl;
    }
    return 0;
}