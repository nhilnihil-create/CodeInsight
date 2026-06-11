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

char str[kN]; int n;

int main() {
	int T = 1; //rd(T);
	while(T--) {
		scanf("%s", str + 1);
		n = strlen(str + 1);
		if(str[1] == '0' || str[n - 1] == '0' || str[n] == '1') {
			printf("-1\n"); return 0;
		}
		for(int i = 1; i <= n / 2; ++i) if(str[i] != str[n - i]) {
			printf("-1\n"); return 0;
		}
		int cnt = 1, lst = 0, lst_cnt = 1;
		for(int i = 2; i <= n / 2; ++i) {
			if(str[i] == '0') continue;
			//printf("i = %d, cnt = %d, lst = %d, lst_cnt = %d\n", i, cnt, lst, lst_cnt);
			for(int j = 1; j < i - lst; ++j) {
				++cnt;
				printf("%d %d\n", lst_cnt, cnt);
			}
			printf("%d %d\n", cnt + 1, lst_cnt);
			lst_cnt = ++cnt;
			lst = i;
		}
		//printf("===\n");
		cnt += 1;
		for(; cnt <= n; ++cnt) printf("%d %d\n", lst_cnt, cnt);
	} return 0;
}