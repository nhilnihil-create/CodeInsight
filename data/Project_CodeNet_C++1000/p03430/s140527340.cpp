#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, k, a[305][305][305], ans;
char s[305];
int main(){
	scanf("%s\n%d", s, &k);
	n = (int)strlen(s);
	rep(i,n) rep(j,n-1-i) rep(l,k+1){
		if(s[i] == s[n-1-j]) a[i+1][j+1][l] = a[i][j][l] + 1;
		else a[i+1][j+1][l] = max({a[i][j+1][l], a[i+1][j][l], l ? a[i][j][l-1]+1 : 0});
	}
	rep(i,n+1) ans = max({ans, (i!=n?a[i][n-1-i][k]*2:0)+1, a[i][n-i][k]*2});
	printf("%d\n", ans);
}