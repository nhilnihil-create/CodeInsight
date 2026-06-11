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
typedef double db;

using namespace std;
const int N = 1100;
int n, m;
struct Point {
	int x,y;
}A[N];
void Solve(int x,int y) {
	FOR(i, 30, 0) {
		int move = 1 << i;
		if(abs(x) >= move) {
			if(x > 0) x -= move,putchar('R');
			else x += move,putchar('L');
		}
		else if(abs(y) >= move) {
			if(y > 0) y -= move,putchar('U');
			else y += move,putchar('D');
		}
		else {
			if(abs(x) > abs(y)) {
				if(x >= 0) x -= move,putchar('R');
				else x += move,putchar('L');
			}
			else {
				if(y >= 0) y -= move,putchar('U');
				else y += move,putchar('D');
			}
		}
	}
}
		
int main() {
	scanf("%d",&n);
	int flag = -1;
	For(i, 1, n) {
		scanf("%d%d",&A[i].x,&A[i].y);
		if(flag != ((A[i].x + A[i].y) & 1)) {
			if(flag != -1) {flag = -1;break;}
			flag = (A[i].x + A[i].y) & 1;
		}
	}
	if(flag == -1) {puts("-1");return 0;}
	cout << (32 - flag) << endl;
	FOR(i, 30, 0) cout << (1 << i) << " " ;
	puts(flag ? " " : "1");
	if(!flag) for(int i = 1;i <= n;++i) ++A[i].y;
	for(int i = 1;i <= n;++i) {
		Solve(A[i].x,A[i].y);
		puts(flag ? "" : "D");
	}
	return 0;
}
