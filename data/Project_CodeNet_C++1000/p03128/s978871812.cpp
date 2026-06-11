#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define alls(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

int n, m;
int a[500000];
int v[10] = {0,2,5,5,4,5,6,3,7,6};
int b[10];

vector<int> ans1, ans2;
vector<int> cur;

void gen(int x, int st)
{
    if (x == 0)
    {
        if (cur.size() > ans2.size() || (cur.size() == ans2.size() && cur > ans2))
        {
            ans2 = cur;
        }
        return;
    }
    for (int d = st; d >= 0; d--)
    {
        if (b[d] && x - v[d] >= 0)
        {
            cur.push_back(d);
            gen(x - v[d], d);
            cur.pop_back();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) b[a[i]]++;

    int opt = -1;
    for (int i = 0; i < 10; i++)
    {
        if (b[i])
        {
            if (opt == -1) opt = i;
            if (v[i] <= v[opt]) opt = i;
        }
    }
    while (n > 60)
    {
        n -= v[opt];
        ans1.push_back(opt);
    }
    gen(n, 9);
    for (int i = 0; i < ans2.size(); i++)
    {
        ans1.push_back(ans2[i]);
    }
    sort(ans1.begin(), ans1.end());
    for (int i = 0; i < ans1.size(); i++) cout << ans1[ans1.size() - 1 - i];
    return 0;
}
