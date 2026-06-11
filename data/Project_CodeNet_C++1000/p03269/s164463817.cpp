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

using std::min;
using std::max;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

ll inq(ll x, ll y, ll mod)
{
    if (y == 0) return 1;
    ll l = inq(x, y / 2, mod);
    if (y % 2) return l * l % mod * x % mod;
    return l * l % mod;
}

ll rev(ll x, ll mod)
{
    return inq(x, mod - 2, mod);
}

inline int nextInt()
{
    int x = 0;
    char c = getchar();
    int mi = (c == '-');
    if (c == '-') c = getchar();
    while ('0' <= c && c <= '9')
    {
        x = 10 * x + c - '0';
        c = getchar();
    }
    if (mi) return x * -1;
    return x;
}

int l;
int n, m;
int a[50000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> l;
    a[1] = 1;
    for (int i = 2; i < 30; i++) a[i] = a[i - 1] * 2;
    for (int i = 2; i < 30; i++)
    {
        if (a[i] <= l)
        {
            n = i;
        }
    }
    struct t{
        int a, b, c;
    };
    vector<t> e;
    int f = 1;
    for (int i = 1; i + 1 <= n; i++)
    {
        e.push_back({i, i + 1, 0});
        e.push_back({i, i + 1, f});
        f *= 2;
    }
    int k = l - a[n];
    int cur = a[n] - 1;
    for (int j = n - 1; j >= 1; j--)
    {
        if (k >= a[j])
        {
            e.push_back({j, n, cur + 1});
            cur += a[j];
            k -= a[j];
        }
    }
    cout << n << " " << e.size() << endl;
    for (int i = 0; i < e.size(); i++)
    {
        cout << e[i].a << " " << e[i].b << " " << e[i].c << endl;
    }
}