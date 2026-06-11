#include<cstdio>
char s[101];
 
int main(){
	int n;
	scanf("%d%s",&n,s+1);
	int cntR = 0;
	for(int i = 1; i <= n; i++) cntR += (s[i]=='R');
	if(cntR>n-cntR) printf("Yes\n");
	else printf("No\n");
	return 0;
}
