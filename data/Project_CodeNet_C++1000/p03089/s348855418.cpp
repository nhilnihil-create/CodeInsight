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
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<vector<int>>
#define vll vector<ll>
#define vllll vector<vector<ll>>
#define ALL(a) (a).begin(), (a).end()
#define sort_v(a) sort(a.begin(), a.end())
#define reverse_v(a) reverse(a.begin(), a.end())

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

//右下左上
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
    ll n, a;
    cin >> n;
    vll b, ans;
    rep(i, 0, n)
    {
        cin >> a;
        b.push_back(a);
    }
    rep(i, 0, n)
    {
        repm(j, b.size() - 1, 0)
        {
            if (b[j] == j + 1)
            {
                ans.push_back(b[j]);
                b.erase(b.begin() + j);
                break;
            }
            else if (b[j] >= j + 1)
                return cout << -1 << endl, 0;
        }
    }
    reverse_v(ans);
    rep(i, 0, n) cout << ans[i] << endl;
}
