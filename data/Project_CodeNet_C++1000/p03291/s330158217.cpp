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
#include <unordered_map>
#include <unordered_set>
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

string s;
ll dp[4][500000];
const ll MOD = 1e9 + 7;

ll inq(ll a, ll q)
{
    if (q == 0) return 1;
    ll l = inq(a, q / 2);
    if (q % 2) return l * l % MOD * a % MOD;
    return l * l % MOD;
}

ll solve(string t)
{
    for (int i = 0; i < s.size(); i++) for (int j = 0; j < 4; j++) dp[j][i] = 0;
    dp[0][0] = 1;
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[j][i] = dp[j][i - 1];
            if (j > 0 && s[i] == t[j - 1]) dp[j][i] = (dp[j][i] + dp[j - 1][i - 1]) % MOD;
        }
    }
    return dp[3][s.size() - 1];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    s = "S" + s;
    int cnt = 0;
    F(i, s.size()) if (s[i] == '?') cnt++;
    ll ans = inq(3, cnt) * solve("ABC") + inq(3, cnt - 1) * solve("AB?") + inq(3, cnt - 1) * solve("A?C") +
             inq(3, cnt - 1) * solve("?BC") + inq(3, cnt - 2) * solve("A??") + inq(3, cnt - 2) * solve("?B?") +
             inq(3, cnt - 2) * solve("??C") + inq(3, cnt - 3) * solve("???");
    cout << ans % MOD;
}
