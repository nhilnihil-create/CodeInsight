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
//#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAXA = 0;

int f[MAXA];
int uf[MAXA];

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

int n;
int a[500000], b[500000];

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    for (int by = 0; by < 29; by++)
    {
        int x = (1 << by);
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) A[i] = a[i] % (2 * x);
        for (int i = 0; i < n; i++) B[i] = b[i] % (2 * x);
        int cnt = 0;
        int p1 = n - 1, p2 = n - 1, p3 = n - 1, p4 = n - 1;
        sort(all(A));
        sort(all(B));
        for (int i = 0; i < n; i++)
        {
            while (p1 >= 0 && A[i] + B[p1] >= x) p1--;
            while (p2 >= 0 && A[i] + B[p2] >= 2 * x) p2--;
            while (p3 >= 0 && A[i] + B[p3] >= 3 * x) p3--;
            while (p4 >= 0 && A[i] + B[p4] >= 4 * x) p4--;
            cnt += p4 - p3 + p2 - p1;
        }
        if (cnt % 2 != 0) ans += x;
    }
    cout << ans;
}
