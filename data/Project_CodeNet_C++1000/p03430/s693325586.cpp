#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
#define db double
#define mo 1000000007
using namespace std;
char s[305];
int f[305][305][305];
int K,ans;
int main(){
	scanf("%s%d",s+1,&K);
	int n=strlen(s+1);
	for (int i=0;i<=K;i++)
		for (int j=1;j<=n;j++)
			for (int k=n;k>j;k--){
				if (i!=0) f[i][j][k]=f[i-1][j-1][k+1]+1;
				f[i][j][k]=max(f[i][j][k],max(f[i][j-1][k],f[i][j][k+1]));
				if (s[j]==s[k]) f[i][j][k]=max(f[i][j][k],f[i][j-1][k+1]+1);
			}
	for (int i=1;i<=n;i++)
		ans=max(ans,2*f[K][i-1][i+1]+1);
	for (int i=0;i<=n;i++)
		ans=max(ans,2*f[K][i][i+1]);
	printf("%d",ans);
}