#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#include<assert.h>
#include<chrono>
#include<random>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
template<typename T>inline void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T>inline void chkmax(T &x,T y){x=x>y?x:y;}
const int MAXN=200005;
int a[MAXN],n,X;
LL S[MAXN];
int main()
{
	n=read();X=read();
	LL ans=0;
	for(int i=1;i<=n;i++)a[i]=read(),ans+=5LL*a[i]+2*X,S[i]=a[i]+S[i-1];
	for(int k=1;k<=n;k++)
	{
		LL sum=1LL*X*(n+k);if(sum>=ans)continue;
		for(int j=n,id=1;j>=1;j-=k,++id)
		{
			int pr=max(0,j-k);
			sum+=(2LL*id+1)*(S[j]-S[pr]);
			if(id==1)sum+=2LL*(S[j]-S[pr]);
			if(sum>=ans)break;
		}chkmin(ans,sum);
	}pr2(ans);
	return 0;
}

