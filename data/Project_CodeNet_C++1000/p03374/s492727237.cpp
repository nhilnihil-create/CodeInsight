#include<bits/stdc++.h> 
#define LL long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=100005;
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
LL n,c,x[N],val[N],bx[N],sv[N],bv[N],f[2][N],g[2][N],ans;
int main()
{
	n=read();c=read();
	for(int i=1;i<=n;i++)
	  x[i]=read(),val[i]=read();
	for(int i=1;i<=n;i++){
		sv[i]=sv[i-1]+val[i];
	}
	for(int i=n;i>=1;i--){
		bx[i]=c-x[i];
		bv[i]=bv[i+1]+val[i];
	}
	for(int i=1;i<=n;i++){
		f[1][i]=max(f[1][i-1],sv[i]-2*x[i]);
		g[1][i]=max(g[1][i-1],sv[i]-x[i]);
	}
	for(int i=n;i>=1;i--){
		f[0][i]=max(f[0][i+1],bv[i]-2*bx[i]);
		g[0][i]=max(g[0][i+1],bv[i]-bx[i]);
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,g[0][i+1]+f[1][i]);
		ans=max(ans,g[1][i]+f[0][i+1]);
	}
	cout<<ans<<endl;
	return 0;
}

