// Nurbakyt Madibek
// Look at my code! IT'S AWESOME

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;
typedef pair < ll, ll > pl;

const int inf = (int)1e9;
const ll infl = (ll)1e18 + 123;
const double eps = 1e-9;

const int MAX_N = (int)1e5 + 123;
const int mod = (int)1e9 + 7;
const int P = 123457;

string s;
int k;

int dp[305][305][305];

int calc(int l, int r, int x) {
    int &res = dp[l][r][x];
    if (res != -1)
        return res;
    if (l == sz(s) || r == -1 || l > r)
        return res = 0;
    if (l == r)
        return res = 1;
    res = max(calc(l + 1, r, x), calc(l, r - 1, x));
    if (s[l] == s[r])
        res = max(res, 2 + calc(l + 1, r - 1, x));
    else if (x > 0)
        res = max(res, 2 + calc(l + 1, r - 1, x - 1));
    return res;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> k;
    memset(dp, -1, sizeof dp);
    cout << calc(0, sz(s) - 1, k) << endl;
    return 0;
}
