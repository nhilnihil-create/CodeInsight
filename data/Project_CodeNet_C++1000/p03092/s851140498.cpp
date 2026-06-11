#include<iostream> A
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int MAXN = 100010;
const LL INF = 9187201950435737471;

int N; int a[MAXN+1],pos[MAXN+1];
LL f[5010][5010]; LL A,B;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(); A=read(),B=read();
	memset(f,127,sizeof(f)); 
	for(int i=1;i<=N;i++) a[i]=read(),pos[a[i]]=i;
	f[0][0]=0; LL ans=INF;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(f[i][j]==INF) continue;
			f[i][j+1]=min(f[i][j+1],(pos[j+1]<=i?0:B)+f[i][j]);
		}
		for(int j=0;j<=N;j++){
			if(f[i][j]==INF) continue;
			if(j+1==a[i+1]){
				f[i+1][j+1]=min(f[i][j],f[i+1][j+1]);
			} else if(j<a[i+1]){
				f[i+1][j]=min(f[i][j]+A,f[i+1][j]);
			} else{
				f[i+1][j]=min(f[i][j],f[i+1][j]);
			}
		} 
	} for(int i=0;i<=N;i++) ans=min(ans,f[N][i]);
	printf("%lld\n",ans);
	return 0;
}


