#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const ull inf = (1ull << 64) - 1;
const int block = 700;

ull par[maxn], x[maxn], ans[maxn], num[maxn];

ull sq (ull x) { return x * x; }

int main() {
    ios_base::sync_with_stdio (false);
    ull n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        par[i] = par[i - 1] + x[i];
    }

    ull Min = inf;
    for (ll num = 1; num <= n; num++) {
        ull ted = num, last = 1;
        ull ans = (num + n) * k;
        for (int i = n; i >= 1; i -= num, last ++) {
            if (last != 1)
                ans += (sq (last + 1) - sq (last)) * (par[i] - par[max (i - num, 0ll)]);
            else {
                ans += (sq (last + 1) + 1) * (par[i] - par[max (i - num, 0ll)]);;
            }
            if (ans >= Min)
                break;
        }
        Min = min (Min, ans);
    }
    cout << Min << endl;
}