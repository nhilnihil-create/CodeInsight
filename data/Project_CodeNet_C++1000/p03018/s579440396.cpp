#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <numeric>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (int i = a; i < n; i++)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool cmp(const pii &a, const pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

ll calc(ll n, ll a, ll b)
{
    string tmp = to_string(n);
    return a * n + b * tmp.size();
}

int main()
{
    string s, t;
    cin >> s;
    ll cnt = 0, ans = 0;
    rep(i, 0, s.size())
    {
        if (i != s.size() - 1 && s[i] == 'B' && s[i + 1] == 'C')
        {
            t += 'D';
            i++;
        }
        else
            t += s[i];
    }
    rep(i, 0, t.size())
    {
        if (t[i] == 'A')
            cnt++;
        else if (t[i] == 'D')
            ans += cnt;
        else
            cnt = 0;
    }
    cout << ans << endl;
}
