#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500100,P=998244353;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
ll ans;
int n,l[N],r[N],ql[N],qr[N],v[N];
bool cmpl(int i,int j){return l[i]<l[j];}
bool cmpr(int i,int j){return r[i]<r[j];}
int mov(int&x,int t){
	int re=0;
	if(x<l[t])re=l[t]-x,x=l[t];
	if(x>r[t])re=x-r[t],x=r[t];
	return re;
}
void solve(){
	ll k=0;int i,il,ir,x;
	for(i=1;i<=n;i++)v[i]=0,ql[i]=qr[i]=i;
	sort(ql+1,ql+n+1,cmpl);
	sort(qr+1,qr+n+1,cmpr);
	ir=1;il=n;x=0;
	for(i=1;i<=n;i++){
		if(i&1){
			while(v[qr[ir]])ir++;
			v[qr[ir]]=1;k+=mov(x,qr[ir]);
		}else{
			while(v[ql[il]])il--;
			v[ql[il]]=1;k+=mov(x,ql[il]);
		}
	}k+=abs(x);
	if(k>ans)ans=k;
}
int main(){
	//freopen("1.out","w",stdout);
	int i;n=read();
	for(i=1;i<=n;i++)l[i]=read(),r[i]=read();
	solve();
	for(i=1;i<=n;i++)swap(l[i],r[i]),l[i]=-l[i],r[i]=-r[i];
	solve();
	printf("%lld\n",ans);
	return 0;
}