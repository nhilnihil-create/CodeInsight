#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <algorithm>
#include <fstream>
#include <climits>
#define mp make_pair
#define Debug(...) fprintf(stdout, __VA_ARGS__)

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;

const int MAXN = 5e3 + 7;

inline void proc_status() {
	ifstream t("/proc/self/status");
	cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>()) << endl;
}

template<typename T> inline T read() {
	T res = 0, flag = 1; char in = getchar();
	while(!isdigit(in)) { if(in == '-') flag = -1; in = getchar(); }
	while(isdigit(in)) { res = (res << 1) + (res << 3) + in - '0'; in = getchar(); }
	return res * flag;
}

template<typename T> inline void chkmax(T &a, T b) { if(a < b) a = b; }
template<typename T> inline void chkmin(T &a, T b) { if(a > b) a = b; }

int n, a, b;
int p[MAXN];

inline void init() {
	n = read<int>(); a = read<int>(); b = read<int>();
	for(int i = 1; i <= n; ++i) p[read<int>()] = i;
//	for(int i = 1; i <= n; ++i) cout << p[i] << endl;
}

LL f[MAXN][MAXN];

inline void solve() {
	memset(f, 0x3f, sizeof f);

	f[1][0] = b; f[1][1] = 0;
	for(int i = 2; i <= n; ++i) {
		for(int j = 0; j < i; ++j) {
			if(p[i] < p[j]) {
				chkmin(f[i][j], f[i - 1][j] + a);
			}
			else {
				chkmin(f[i][j], f[i - 1][j] + b);
			}
//			printf("[%d %d] %lld\n", i, j, f[i][j]);
		}
		for(int j = 0; j < i; ++j) {
			if(p[j] < p[i]) chkmin(f[i][i], f[i - 1][j]);
		}
//		printf("[%d %d] %lld\n", i, i, f[i][i]);
//		puts("");
	}
//	cout << endl;
	LL ans = LLONG_MAX;
	for(int i = 0; i <= n; ++i) {
//		cout << f[n][i] << endl;
		chkmin(ans, f[n][i]);
	}
	printf("%lld\n", ans);
}

int main() {

	init();
	solve();

	return 0;
}

