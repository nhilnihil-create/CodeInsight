#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 3010;
const int MOD  = 1e9+7;

int n;
char s[MAXN];

int f[MAXN][MAXN];

int main()
{
	scanf("%d%s",&n,s+1);
	f[1][1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(s[i-1] == '>') f[i][j] = (f[i-1][i-1] - f[i-1][j-1] + MOD) % MOD;
			else f[i][j] = f[i-1][j-1];
			f[i][j] = (f[i][j] + f[i][j-1]) % MOD;
		}
	}
	printf("%d\n",f[n][n]);
	return 0;
}