#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 5005
#define ll long long 
using namespace std;

int n,i,j,k,a[maxn],A,B,s[maxn][maxn];
ll f[maxn];

int pd(int l,int r){
	return (s[r-1][a[r]-1]-s[l][a[r]-1])-(s[r-1][a[l]]-s[l][a[l]])==0;
}

ll cnt1(int l,int r){
	return s[r-1][a[l]-1]-s[l][a[l]-1];
}
ll cnt2(int l,int r){
	if (r==n+1) return 0;
	return (s[r-1][n]-s[r-1][a[r]])-(s[l][n]-s[l][a[r]]);
}

int main(){
	scanf("%d%d%d",&n,&A,&B),a[0]=0,a[n+1]=n+1;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) s[i][j]=s[i-1][j]+(a[i]<=j);
	memset(f,127,sizeof(f)),f[0]=0;
	for(i=1;i<=n+1;i++) for(j=0;j<i;j++) 
		if (a[i]>a[j]&&pd(j,i))
			f[i]=min(f[i],f[j]+cnt1(j,i)*B+cnt2(j,i)*A);
	printf("%lld",f[n+1]);
}