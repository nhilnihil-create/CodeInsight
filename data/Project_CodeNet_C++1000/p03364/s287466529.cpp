#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (510)
//n<=500

int main(void) {
	int n;
	int x, y;
	bool v;
	int ans = 0;
	char a[N][N];
	f(i, N) {
		f(j, N)a[i][j] = 0;
	}
	scanf("%d", &n);
	f(i, n) {
		scanf("%s", a[i]);
	}
	f(ii, n) {
		v = true;
		f(i, n) {
			f(j, n) {
				x = (i + ii) % n;
				y = (j + ii) % n;
				if (a[x][j] != a[y][i])v = false;
			}
			if (!v)break;
		}
		if (v)ans += n;
	}
	printf("%d\n", ans);
	return 0;
}