#include <bits/stdc++.h>

#define debug(...) fprintf(stderr,__VA_ARGS__)
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long LL;
const int MAXN=150 + 10;

char inis[MAXN*2], s[MAXN], t[MAXN];
int n,m , f[MAXN][MAXN][MAXN],mdf, g[MAXN*2][MAXN*2][MAXN];

int main(){
	
	scanf("%s", s+1);scanf("%d", &mdf);
	mdf=min(mdf, 150);
	for (int i=1,j=n; i<=n; i++,j--) t[j]=s[i];
	int n= strlen(s+1);
	memset(g, 0 ,sizeof(g));
	for (int i=1; i<=n; i++) g[i][i][0] = 1;
	for (int L=2; L<=n; L++)
		for (int i=1; i<=n; i++){
			int j=i+L-1;
			for (int k=0; k<=mdf; k++){
				int &cur= g[i][j][k];
				cur= max(g[i+1][j][k], g[i][j-1][k]);
				if ( s[i]==s[j]) cur= max(cur, g[i+1][j-1][k]+2);
					else
				if ( k) cur= max(cur, g[i+1][j-1][k-1]+2);
			}
		}
	int ans=0;
	for (int i=0; i<=mdf; i++) ans= max(ans , g[1][n][i]);
	printf("%d\n", ans);
	return 0;
}
