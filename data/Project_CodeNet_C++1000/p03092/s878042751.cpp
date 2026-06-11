#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int n,a,b,i,j,p[N],s[N][N],x,y;
ll f[N],ans;
int ask(int a,int b,int c,int d){return s[b][d]-s[b][c-1]-s[a-1][d]+s[a-1][c-1];}
int main(){
	scanf("%d%d%d",&n,&a,&b);ans=1ll*n*min(a,b);
	for(i=1;i<=n;++i)for(scanf("%d",p+i),memcpy(s[i]+1,s[i-1]+1,n<<2),j=p[i];j<=n;++j)++s[i][j];
	for(i=1;i<=n;++i){
		x=ask(1,i-1,p[i]+1,n);f[i]=1ll*x*a+1ll*(i-1-x)*min(a,b);
		for(j=1;j<i;++j)if(p[j]<p[i]){
			x=ask(j+1,i-1,1,p[j]-1);y=ask(j+1,i-1,p[i]+1,n);
			f[i]=min(f[i],1ll*x*b+1ll*y*a+1ll*(i-j-1-x-y)*min(a,b)+f[j]);
		}
		x=ask(i+1,n,1,p[i]-1);ans=min(ans,f[i]+1ll*x*b+1ll*(n-i-x)*min(a,b));
	}
	printf("%lld\n",ans);
	return 0;
}