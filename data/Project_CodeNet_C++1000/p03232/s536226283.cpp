#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9;

int n;
int a[500000];

int w2[500010];
int f[500010];
int uf[500010];
int flen1[500010];
int flen2[500010];
int add[500010];

long long inq(long long a, long long b)
{
    if (b == 0) return 1;
    ll l = inq(a, b / 2);
    if (b % 2) return l * l % MOD * a % MOD;
    return l * l % MOD;
}

long long cnk(long long n, long long k)
{
    if (k < 0 || k > n) return 0;
    return f[n] * uf[k] % MOD * uf[n - k] % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= 100000; i++) f[i] = f[i - 1] * i % MOD;
    for (int i = 0; i <= 100000; i++) uf[i] = inq(f[i], MOD - 2);

    int x = 3, y = 2;
    for (int len = 1; len <= n; len++)
    {
        flen2[len] = f[n] * inq(x, MOD - 2) % MOD;
        x += len + 2;
        flen1[len] = f[n] * inq(y, MOD - 2) % MOD;
        y++;
    }

    add[1] = f[n];

    for (int l = 1; l <= 1; l++)
    {
        for (int r = 1; r < n; r++)
        {
            int len = r - l + 1;
            add[l] = (add[l] + flen1[len]) % MOD;
            add[r + 1] = (add[r + 1] + MOD - flen1[len]) % MOD;
        }
    }

    for (int l = 2; l <= n; l++)
    {
        for (int r = n; r <= n; r++)
        {
            int len = r - l + 1;
            add[l] = (add[l] + flen1[len]) % MOD;
            add[r + 1] = (add[r + 1] + MOD - flen1[len]) % MOD;
        }
    }

    for (int i = 2; i <= n; i++) flen2[i] = (flen2[i] + flen2[i - 1]) % MOD;

    if (n % 2 == 0)
    {
        for (int i = 2; i <= n / 2; i++)
        {
            add[i] = (add[i] + MOD - flen2[i - 2] + flen2[n - i]) % MOD;
        }
        for (int i = n - 1; i > n / 2; i--)
        {
            add[i + 1] = (add[i + 1] + MOD + flen2[n - i - 1] - flen2[i - 1]) % MOD;
        }
    }

    if (n % 2 == 1)
    {
        for (int i = 2; i <= n / 2 + 1; i++)
        {
            add[i] = (add[i] + MOD - flen2[i - 2] + flen2[n - i]) % MOD;
        }
        for (int i = n - 1; i > n / 2; i--)
        {
            add[i + 1] = (add[i + 1] + MOD + flen2[n - i - 1] - flen2[i - 1]) % MOD;
        }
    }

    int g = 0;
    for (int i = 1; i <= n; i++)
    {
        g = (g + add[i]) % MOD;
        w2[i] = g;
    }

    F(i, n) cin >> a[i];

    //for (int i = 1; i <= n; i++) cout << w2[i] << " ";
    //cout << endl;

    long long ans = 0;
    F(i, n) ans = (ans + 1LL * a[i] * w2[i + 1]) % MOD;
    cout << ans << endl;
}
