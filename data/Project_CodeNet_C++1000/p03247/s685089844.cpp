#include <stdio.h>
#include <cmath>

using namespace std;

const long long MAXM = 40;
const int MAXN = 1000;

long long n, v[MAXN][2], ps[MAXM + 1], sum[MAXM + 1];
char sol[MAXN][MAXM];

bool wk(long long x, long long y, long long r) {
	if(abs(x) + abs(y) <= r) {
		return true;
	} else {
		return false;
	}
}

int main ()
{	

	int m = MAXM;
	scanf("%lld", &n);

	int rest = -1;
	for(int i = 0; i < n; i++) {
		scanf("%lld %lld", &v[i][0], &v[i][1]);
		int mod = (v[i][0] + v[i][1]) & 1;
		if(rest == -1) {
			rest = mod;
		} else {
			if(rest != mod) {
				printf("-1\n");
				return 0;
			}
		}
	}

	if(rest == 1) {
		for(int i = 0; i < m; i++) {
			ps[i] = (1LL << (m - i - 1));
		}
	} else {
		for(int i = 1; i < m; i++) {
			ps[i - 1] = (1LL << (m - i - 1));
		}
		ps[m - 1] = 1;
	}

	sum[m] = 0;
	ps[m] = 0;
	for(int i = m - 1; i >= 0; i--) {
		sum[i] = ps[i] + sum[i + 1];
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char afis;
			if(wk(v[i][0] - ps[j], v[i][1], sum[j + 1])) {
				afis = 'R';
				v[i][0] -= ps[j];
			} else {
				if(wk(v[i][0] + ps[j], v[i][1], sum[j + 1])) {
					afis = 'L';
					v[i][0] += ps[j];
				} else {
					if(wk(v[i][0], v[i][1] - ps[j], sum[j + 1])) {
						afis = 'U';
						v[i][1] -= ps[j];
					} else {
						if(wk(v[i][0], v[i][1] + ps[j], sum[j + 1])) {
							afis = 'D';
							v[i][1] += ps[j];
						}
					}
				}
			}
			sol[i][j] = afis;
		}
		if(v[i][0] != 0 || v[i][1] != 0) {
			printf("-1\n");
			return 0;
		}
	}

	printf("%d\n", m);
	for(int i = 0; i < m; i++) {
		printf("%lld ", ps[i]);
	}
	printf("\n");

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%c", sol[i][j]);
		}
		printf("\n");
	}


	return 0;
}