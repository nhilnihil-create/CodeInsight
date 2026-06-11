#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[1005], b[1005];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d%d", &a[i], &b[i]);
	
	int cs = 0;
	rep(i, n) cs = a[i] + b[i] & 1;
	rep(i, n) if(cs != (a[i] + b[i] & 1)) {
		printf("-1\n");
		return 0;
	}
	
	printf("40\n");
	int cur = 1;
	rep(i, 20) {
		printf("%d %d ", cur, i == 0 && cs == 1 ? 2 : cur);
		cur *= 3;
	}
	printf("\n");
	
	rep(i, n) {
		int ca = a[i], cb = b[i];
		cur = 1;
		rep(i, 20) {
			int da = (ca / cur) % 3, db = (cb / cur) % 3;
			if(da == 2) da = -1;
			if(db == 2) db = -1;
			if(da == -2) da = 1;
			if(db == -2) db = 1;
			if(i == 0 && cs == 1) {
				if(da + db & 1) {
					if(da == -1) {
						printf("RL");
						ca ++;
					} else if(da == 1) {
						printf("LR");
						ca --;
					}
					if(db == -1) {
						printf("UD");
						cb ++;
					} else if(db == 1) {
						printf("DU");
						cb --;
					}
				} else {
					if(da == 1) {
						printf("R");
						ca --;
					} else if(da == -1) {
						printf("L");
						ca ++;
					}
					if(db == 1) {
						printf("D");
						cb += 2;
					} else if(db == -1) {
						printf("U");
						cb -= 2;
					}
					if(da == 0 && db == 0) {
						printf("LL");
						ca += 3;
					}
				}
			} else {
				if(da + db & 1) {
					if(da == -1) {
						printf("RR");
						ca -= 2 * cur;
					} else if(da == 1) {
						printf("LL");
						ca += 2 * cur;
					}
					if(db == -1) {
						printf("UU");
						cb -= 2 * cur;
					} else if(db == 1) {
						printf("DD");
						cb += 2 * cur;
					}
				} else {
					if(da == 1) {
						printf("R");
						ca -= cur;
					} else if(da == -1) {
						printf("L");
						ca += cur;
					}
					if(db == 1) {
						printf("U");
						cb -= cur;
					} else if(db == -1) {
						printf("D");
						cb += cur;
					}
					if(da == 0 && db == 0) printf("LR");
				}
			}
			cur *= 3;
		}
		printf("\n");
	}
	return 0;
}