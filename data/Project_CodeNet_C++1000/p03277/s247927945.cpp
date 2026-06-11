#include<bits/stdc++.h>
#define INTMAX 2147483647LL
#define PII pair<int,int>
#define MP make_pair
#define fir first
#define sec second
#define pb push_back
#define re register
#define lc c[x][0]
#define rc c[x][1]
using namespace std;
typedef long long ll;
const double Pi=acos(-1.0);
const int Inf=0x3f3f3f3f;
const int MAXN=1e5+10; 
inline int read(){
	re int x=0,f=1,ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch))x=x*10+ch-48,ch=getchar();
	return x*f;
}
inline ll readll(){
	re ll x=0,f=1,ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch))x=x*10+ch-48,ch=getchar();
	return x*f;
}

int n,ans;
int a[MAXN],sum[MAXN];
ll tot,BIT[MAXN<<1];

inline int lowbit(int x){return x&(-x);}
inline void Update(int x,int v){for(int i=x;i<=(n<<1)+2;i+=lowbit(i)) BIT[i]+=v;}
inline ll Query(int x){ll res=0;for(int i=x;i;i-=lowbit(i)) res+=BIT[i];return res;}

inline bool Check(int mid){
	memset(BIT,0,sizeof(BIT));
	for(int i=1;i<=n;++i){
		sum[i]=(a[i]>=mid)?1:-1;
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=n;++i) sum[i]+=n+1;
	
	ll cnt=0;Update(n+1,1);
	for(int i=1;i<=n;++i){
		cnt+=Query(sum[i]);
		Update(sum[i],1);
	}
	return cnt>=tot-tot/2;
}
int main(){
	n=read();tot=1ll*n*(n+1)/2;
	for(int i=1;i<=n;++i) a[i]=read();
	int l=1,r=1e9+10;
	while(l<=r){
		int mid=(l+r)>>1;
		if(Check(mid)){
			ans=mid;l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}