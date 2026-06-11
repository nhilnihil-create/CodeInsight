#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repm(i, a, n) for (ll i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vs vector<string>
#define vii vector<vector<int>>
#define vll vector<ll>
#define vllll vector<vector<ll>>
#define vd vector<double>
#define ALL(a) (a).begin(), (a).end()
#define sort_v(a) sort(a.begin(), a.end())
#define reverse_v(a) reverse(a.begin(), a.end())
#define fi first
#define se second

void print(bool c)
{
    (c) ? (cout << "Yes" << endl) : (cout << "No" << endl);
}

void Print(bool c)
{
    (c) ? (cout << "YES" << endl) : (cout << "NO" << endl);
}

//最小公倍数
template <typename T>
T gcd(T a, T b)
{
    while (1)
    {
        if (a < b)
            swap(a, b);
        if (b == 0)
            break;
        a %= b;
    }
    return a;
}

//最大公約数
template <typename T>
T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}
//セカンドキー->ファーストキーの順ソート
bool cmp(const pii &a, const pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int eve(int x)
{
    if (x % 400 == 0)
        return 1;
    if (x % 100 == 0)
        return 0;
    if (x % 4 == 0)
        return 1;
    return 0;
}

int main(void)
{
    int n;
    cin >> n;
    vll v(n);
    rep(i, 0, n) cin >> v[i];

    map<ll, ll> m1, m2;
    rep(i, 0, n)(i % 2 == 0) ? m1[v[i]]++ : m2[v[i]]++;
    pll m11, m12, m21, m22;
    for (auto x : m1)
    {
        if (x.second > m11.second)
            m12 = m11, m11 = x;
        else if (x.second > m12.second)
            m12 = x;
    }
    for (auto x : m2)
    {
        if (x.second > m21.second)
            m22 = m21, m21 = x;
        else if (x.second > m22.second)
            m22 = x;
    }
    ll ans = 0;
    if (m11.first != m21.first)
        ans = (n + 1) / 2 - m11.second + n / 2 - m21.second;
    else
    {
        if (m11.second + m22.second > m21.second + m12.second)
            ans = (n + 1) / 2 - m11.second + n / 2 - m22.second;
        else
            ans = (n + 1) / 2 - m21.second + n / 2 - m12.second;
    }
    cout << ans << endl;
}