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

long long min(long long a, long long b) {return a < b ? a : b;}
long long min(int a, long long b) {return a < b ? a : b;}
long long min(long long a, int b) {return a < b ? a : b;}
long long min(int a, int b) {return a < b ? a : b;}

long long max(long long a, long long b) {return a > b ? a : b;}
long long max(int a, long long b) {return a > b ? a : b;}
long long max(long long a, int b) {return a > b ? a : b;}
long long max(int a, int b) {return a > b ? a : b;}

#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const int N = 522220;
const int MOD = 1e9 + 7;
const double eps = 1e-8;

int n, x, a[N];
int ans;
int v[N];
int p[N];

int P(int i)
{
    if (i >= 0) return p[i];
    return 0;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    v[0] = 5;
    v[1] = 5;
    for (int i = 2; i < n; i++) v[i] = v[i - 1] + 2;
    reverse(a, a + n);
    for (int i = 0; i < n; i++)
        ans += 5 * a[i] + x, p[i] = P(i - 1) + a[i];
    for (int i = n; i < 2 * n; i++) p[i] = p[i - 1];
    for (int block_size = 1; block_size <= n; block_size++)
    {
        int res = x * block_size;
        int j = -1;
        for (int i = block_size - 1; i < n + block_size; i += block_size)
        {
            res += v[i / block_size] * (P(i) - P(i - block_size));
            if (res > ans) break;
        }
        ans = min(ans, res);
    }
    cout << ans + n * x;
}
