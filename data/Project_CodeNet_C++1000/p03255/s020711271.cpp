#include<bits/stdc++.h>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define For(i,j,k) for(Rint i=(j);i<=(k);i++)
#define Fordown(i,j,k) for(Rint i=(j);i>=(k);i--)

using namespace std;
typedef long long LL;

template<typename T>inline void read(T &x){
	x=0;T w=1,ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}

const LL INF=0x7f7f7f7f7f7f7f7f;
const int N=2e5+10;
int n,m;
int a[N];
LL Ans=INF,sum[N];

int main(){
	read(n);read(m);
	For(i,1,n)read(a[i]),sum[i]=a[i]+sum[i-1];
	For(i,1,n){
		int pos=n;LL res=0;
		For(j,1,n/i+1){
			int p=max(0,pos-i);
			res+=1LL*max(5,2*j+1)*(sum[pos]-sum[p]);
			if(res>Ans)break;
			pos=p;
		}
		if(res>Ans)continue;
		res+=1LL*(i+n)*m;
		Ans=min(Ans,res);
	}
	printf("%lld\n",Ans);
	return 0;
}