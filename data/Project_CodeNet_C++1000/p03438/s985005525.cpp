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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repm(i, a, n) for (int i = a; i >= n; i--)
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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
    ll n;
    cin >> n;
    vll a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    ll ca = 0, cb = 0;
    rep(i, 0, n)
    {
        if (a[i] == b[i])
            continue;
        if (a[i] > b[i])
            cb += a[i] - b[i];
        else
        {
            if ((b[i] - a[i]) % 2 == 0)
                ca += (b[i] - a[i]) / 2;
            else
            {
                ca += (b[i] - a[i]) / 2 + 1;
                cb++;
            }
        }
    }
    print(ca >= cb);
}