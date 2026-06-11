#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
using namespace std;
namespace io{
	const int Sz=1<<13;
	char ibuf[Sz],*ips=ibuf+Sz-1;
	inline int getchar(){
		if(++ips==ibuf+Sz)fread(ips=ibuf,1,Sz,stdin);
		return *ips;
	}
	char obuf[Sz],*ops=obuf;
	inline void flush(){
		fwrite(obuf,1,ops-obuf,stdout);
		ops=obuf;fflush(stdout);
	}
	inline void putchar(int c){
		if(ops==obuf+Sz)flush();
		*ops=c,ops++;
	}
	void gets(char *s){
		int c=getchar();
		while(c<=32)c=getchar();
		while(c>32)*s=c,++s,c=getchar();
		*s=0;
	}
	void puts(const char *s){
		while(*s)putchar(*s),++s;
	}
}
#define getchar io::getchar
#define putchar io::putchar
#define gets io::gets
#define puts io::puts
int read(){
	int x=0,f=1,c=getchar();
	for(;c<48||c>57;c=getchar())
		if(c=='-')f=-f;
	for(;c>=48&&c<=57;c=getchar())
		x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
void write(ll x){
	int stk[20],tp=0;
	if(!x)putchar(48);
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)stk[tp++]=(x-x/10*10)^48;
	for(;tp;)putchar(stk[--tp]);
}
struct Flusher{~Flusher(){io::flush();}}flusher;
// ------------------------- Template End ------------------------- //
const int N=5005;
int n,A,B;
int p[N],ps[N];
ll dp[N][N],mndp[N][N];
const ll inf=0x3f3f3f3f3f3f3f3f;
void chkmin(ll &x,ll y){if(y<x)x=y;}
int main(){
	n=read(),A=read(),B=read();
	for(int i=0;i<n;++i)p[i]=read(),ps[p[i]]=i;
	memset(dp,0x3f,sizeof dp);dp[0][0]=0;
	memset(mndp,0x3f,sizeof mndp);
	for(int i=0;i<=n;++i)mndp[0][i]=0;
	for(int i=1;i<=n;++i)for(int j=0;j<=n;++j){
		chkmin(dp[i][j],mndp[i-1][j]+(ps[i]==j?0:(ps[i]<j?A:B)));
		if(j)mndp[i][j]=mndp[i][j-1];chkmin(mndp[i][j],dp[i][j]);
	}
	write(mndp[n][n]);putchar('\n');
	return 0;
}

