#include <bits/stdc++.h>
#define llint long long
#define rg register
#define RI register int
#define RC register char
#define rg register
#define ed putchar('\n')
#define space putchar(' ')
#define Pair pair<int,int >
using namespace std;
	
template <typename tp> inline void read(tp &x)
{		
	x=0;
	RI f=1;
	RC c=getchar();
	while(c<'0' || c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	x*=f;
}	
	
template <typename tp> inline void print(tp x)
{	
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0'); 
}

#define int long long
const int N=1e6+10;
const int mod=998244353; 
int n,a,b,k; 
int jc[N];
int jc_inv[N];
int ans;

inline int mul(int x,int y)
{
	int res=1;
	for(;y;y>>=1)
	{
		if(y&1) res=(res*x)%mod;
		x=(x*x)%mod;
	}
	return res;
}

inline int C(int x,int y)
{
	if(y>x) return 0;
	int tmp1=jc[x];
	int tmp2=jc_inv[y];
	int tmp3=jc_inv[x-y];
	tmp1=(tmp1*tmp2)%mod;	
	tmp1=(tmp1*tmp3)%mod;
	return tmp1;
}

signed main()
{
	jc[0]=1;jc_inv[0]=1;//别忘了初始化这里 不然会疯狂WA 
	for(RI i=1;i<=300002;++i) jc[i]=(jc[i-1]*i)%mod,jc_inv[i]=mul(jc[i],mod-2);
	read(n),read(a),read(b),read(k);
	
	for(RI R=0;R<=n;++R)
	{
		if(R*a>k) break;
		int B=k-R*a;
		if(B%b) continue;
		B/=b;
		ans=(ans + (C(n,R) * C(n,B)) %mod) %mod;				
	}
	print(ans);
	return 0;
}