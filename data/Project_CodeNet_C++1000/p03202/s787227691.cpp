#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[kN];
std::map <int, int> inc;
inline bool Incr(int mid, int k) {
	++inc[k];
	//printf("%d %d\n", k, inc[k]);
	for(; k > 1 && inc[k] >= mid; --k) {
		inc[k - 1] += inc[k] / mid;
		inc[k] %= mid;
	}
	if(k && inc[k] >= mid) return false;
	return true;
}
bool Check(int mid) {
	inc.clear();
	for(int i = 1; i <= n; ++i) {
		if(a[i] <= a[i - 1]) {
			if(!Incr(mid, a[i])) return false;
			for(auto it = inc.upper_bound(a[i]); it != inc.end(); ) {
				it = inc.erase(it);
			}
		}
	}
	return true;
}
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		bool flag = true;
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(a[i] <= a[i - 1]) flag = false;
		}
		if(flag) printf("1\n");
		else {
			int l = 2, r = n;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(Check(mid)) r = mid;
				else l = mid + 1;
				//printf("==%d==\n", mid);
			}
			printf("%d\n", l);
		}
	} return 0;
}