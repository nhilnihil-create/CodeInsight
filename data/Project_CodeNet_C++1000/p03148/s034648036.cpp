// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define String std::string
#define fi first
#define se second
#define mp std::make_pair
#define Pair std::pair<int, int>
#define Map std::map< int, int >
#define Vector std::vector<int>
 
using std::cin;
using std::cout;
using std::endl;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int N = 100000 + 5;
const int M = 1000 + 5;
const int K = 1e7 + 5;
const int MOD = 1e9 + 7;
const int inv2 = 500000004;
const int LOG = 40;
const ull BASE = 19260817;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
const double PI = acos(-1);
 
template<class T>
inline T readT() {
    T res = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) res = (res << 1) + (res << 3) + ch - '0';
    return res * f;
}
#define read readT<int>

int n, k;
ll sum, cnt, ans;
Pair ss[N];
Map map;
std::stack< Pair > s;

inline bool cmp(const Pair &a, const Pair &b) {
    return a.se > b.se;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) ss[i].fi = read(), ss[i].se = read();
    std::sort(ss + 1, ss + n + 1, cmp);
    for (int i = 1; i <= k; i++) {
        if (!map.count(ss[i].fi)) map[ss[i].fi] = 1, cnt++;
        else s.push(ss[i]);
        sum += ss[i].se;
    }
    ans = cnt * cnt + sum;
    for (int i = k + 1; i <= n; i++) {
        if (s.empty()) break;
        if (map.count(ss[i].fi)) continue;
        Pair tmp = s.top();
        s.pop();
        sum -= tmp.se;
        sum += ss[i].se;
        cnt++;
        map[ss[i].fi] = 1;
        ans = std::max(ans, cnt * cnt + sum);
    }
    printf("%lld\n", ans);
    return 0;
}