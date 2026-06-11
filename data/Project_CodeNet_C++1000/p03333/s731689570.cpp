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
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
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
const int MAXN=100005;
struct node{int p,o;}w[2*MAXN];int n;
bool cmp(node n1,node n2){return n1.p<n2.p;}
int main()
{
	n=read();int tot=0;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		w[++tot].p=x;w[tot].o=0;
		w[++tot].p=y;w[tot].o=1;
	}w[++tot].p=0;w[tot].o=0;w[++tot].p=0;w[tot].o=1;
	sort(w+1,w+1+tot,cmp);LL ans=0;
	int pres=0,sufs=0;
	for(int i=1;i<=tot;i++)sufs+=(w[i].o==0);
	for(int i=1;i<tot;i++)
	{
		int len=w[i+1].p-w[i].p;
		sufs-=(w[i].o==0);pres+=(w[i].o==1);
		ans+=2LL*len*min(pres,sufs);
	}pr2(ans);
	return 0;
}
