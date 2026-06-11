#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define eps 1e-18
inline ll read()
{
    ll tmp=0; char c=getchar(),f=1;
    for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
    for(;'0'<=c&&c<='9';c=getchar())tmp=(tmp<<3)+(tmp<<1)+c-'0';
    return tmp*f;
}
using namespace std;
char s[310];
int f[2][310][310];
int n,m;
int main()
{
	int i,j,k;
	scanf("%s",s); n=strlen(s); m=read();
	int ans=0;
	for(k=0;k<=m;k++){
		for(i=0;i<n;i++)
			f[k&1][i][i]=1,f[k&1][i+1][i]=0;
		for(i=1;i<n;i++)
			for(j=0;j+i<n;j++){
				int l=j,r=j+i;
				f[k&1][l][r]=max(f[k&1][l+1][r],f[k&1][l][r-1]);
				if(s[l]==s[r])f[k&1][l][r]=max(f[k&1][l][r],f[k&1][l+1][r-1]+2);
				else if(k>0)f[k&1][l][r]=max(f[k&1][l][r],f[(k&1)^1][l+1][r-1]+2);
			}
		
		ans=max(ans,f[k&1][0][n-1]);
	}
	printf("%d\n",ans);
}