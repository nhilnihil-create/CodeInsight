#include<bits/stdc++.h>
#define REP(i,b,e) for(int i=b; i<e; i++)

int main(){
	int n;
	scanf("%d", &n);
	std::bitset<10> f[n];
	REP(i, 0, n){
		REP(j, 0, 10){
			getchar();
			if(getchar()%2) f[i].set(j);
			else f[i].reset(j);
		}
	}
	
	int p[n][11];
	REP(i, 0, n) REP(j, 0, 11) scanf("%d", &p[i][j]);

	int c[n], ans = -1e9;
	REP(i, 1, 1<<10){
		memset(c, 0, 4*n);
		REP(j, 0, 10) if((i>>j)&1) {
			REP(I, 0, n) if(f[I][j]) {
				c[I]++;
			}
		}
		int tmp = 0;
		REP(I, 0, n) tmp += p[I][c[I]];
		if(ans<tmp) ans = tmp;
	}

	printf("%d\n", ans);
	return 0;
}

