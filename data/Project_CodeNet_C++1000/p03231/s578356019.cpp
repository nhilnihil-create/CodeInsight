#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
//#include <ctype.h>
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
#define ALL(a) (a).begin(), (a).end()
#define sort_v(a) sort(a.begin(), a.end())
#define fi first
#define se second

void print(bool c)
{
    if (c)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void Print(bool c)
{
    if (c)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

ll gcdll(ll a, ll b)
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

ll lcmll(ll a, ll b)
{
    return a * b / (gcdll(a, b));
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool cmp(const pii &a, const pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main(void)
{
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    ll l = gcdll(n, m), res = n * m / l;
    n /= l;
    m /= l;

    rep(i, 0, l)
    {
        if (s[i * n] != t[i * m])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << res << endl;
}