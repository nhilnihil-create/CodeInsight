//author Eterna
#define Hello the_cruel_world!
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<climits>
#include<deque>
#include<functional>
#include<numeric>
#include<unordered_map>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define pb(x) push_back(x)
#define lowbit(x) (x & -x)
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\in.txt", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\out.txt", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define outd(x) printf("%d\n", x)
#define outld(x) printf("%lld\n", x)
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 1e5;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
inline int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
inline ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
ll fsum(ll x) {
	ll a = 0;
	while (x) {
		a += (x % 10);
		x /= 10;
	}
	return a;
}
vector<ll>v;
int k;
int main()
{
	for (int i = 1; i < 10; i++) v.push_back(i);
	v.push_back(19);
	cin >> k;
	ll last = 19;
	while (v.size() < k) {
		ll p = fsum(last);
		ll add = 1;
		while ((last + add)*fsum(last + add * 2) > (last + 2 * add)*fsum(last + add)) add *= 10;
		last += add;
		v.push_back(last);
	}
	for (int i = 0; i < k; i++)cout << v[i] << endl;
	return 0;
}