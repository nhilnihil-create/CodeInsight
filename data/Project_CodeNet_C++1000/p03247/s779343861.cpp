#include<bits/stdc++.h>
#include<bits/extc++.h>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define go(x, i) for(register int i = head[x]; i; i = nxt[i])
#define For(i, a, b) for(register int i = (a), i##_end_ = (b); i <= i##_end_; ++ i)
#define FOR(i, a, b) for(register int i = (a), i##_end_ = (b); i >= i##_end_; -- i)
#define debug(x) cout << #x << " = " << x << endl
#define mem(a, b) memset(a, b, sizeof(a))
#define cpy(a, b) memcpy(a, b, sizeof(a))
#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define inf (0x3f3f3f3f)
#define INF (1e18)
#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef std::pair<ll, int> PLI;
typedef std::pair<int, int> PII;
typedef long double ldb;
typedef double db;

using namespace std;
const int N = 1e3 + 10;

int n, m, d[N];

struct Point {
	int x, y;
}A[N];

void Solve(int x, int y) {
	FOR(i, 30, 0) {
		int now = 1 << i;
		if(abs(x) >= now) {
			if(x > 0) x -= now, putchar('R');
			else x += now, putchar('L');
		}
		else if(abs(y) >= now) {
			if(y > 0) y -= now, putchar('U');
			else y += now, putchar('D');
		}
		else {
			if(abs(x) > abs(y)) {
				if(x < 0) x += now, putchar('L');
				else x -= now, putchar('R');
			}
			else {
				if(y < 0) y += now, putchar('D');
				else y -= now, putchar('U');
			}
		}
	}
	if(x != 0 || y != 0) puts("fuck");
}

int main() {
#ifdef ylsakioi
	file("d");
#endif
	cin >> n; For(i, 1, n) cin >> A[i].x >> A[i].y;
	int flag = abs(A[1].x + A[1].y) & 1;
	For(i, 2, n) if((abs(A[i].x + A[i].y) & 1) ^ flag) return puts("-1"), 0;
	cout << (32 - flag) << endl;
	FOR(i, 30, 0) cout << (1 << i) << ' ';
	puts(flag ? "" : "1");
	if(!flag) For(i, 1, n) ++ A[i].y;
	For(i, 1, n) {
		Solve(A[i].x, A[i].y); 
		puts(flag ? "" : "D");
	}
	return 0;
}
