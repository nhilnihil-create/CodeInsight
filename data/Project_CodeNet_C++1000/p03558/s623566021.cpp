#include <bits/stdc++.h>
using namespace std;

int n;
int memo[45][100000], used[45][100000];
int solve(int d, int m){
	if(d == 0 && m == 0)return 1;
	if(memo[d][m])return memo[d][m];
	if(used[d][m])return memo[d][m] = 2;
	used[d][m] = 1;
	
	int res = 2;
	for(int i = 0;i < 10;i++)if(d-i >= 0){
		res = solve(d-i, (m*10+i)%n);
		if(res == 1)break;
	}
	return memo[d][m] = res;
}

int main(){
	scanf("%d", &n);
	int lim = 0, m = n;
	while(0 < m){
		lim += m%10;
		m /= 10;
	}
	for(int ans = 1;ans < lim;ans++){
		int res = solve(ans, 0);
		if(res == 1){
			printf("%d\n", ans);
			return 0;
		}
	}
	printf("%d\n", lim);
	return 0;
}