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
const int MAXN=100005;
vector<int> nxt[MAXN];
void ins(int x,int y){nxt[x].emplace_back(y);}
int id[MAXN],n;LL D[MAXN],C[MAXN];
bool cmp(int n1,int n2){return D[n1]<D[n2];} 
int siz[MAXN];
void gg(){pr2(-1);exit(0);}
LL dis[MAXN],tot[MAXN];
void getdis(int x,int fa)
{
	tot[x]=1;
	for(auto y:nxt[x])if(y^fa)getdis(y,x),tot[x]+=tot[y],dis[x]+=dis[y]+tot[y];
}
void query(int x,int fa,LL d1,LL d2)
{
	if(dis[x]+d1!=D[x])gg();
	for(auto y:nxt[x])if(y^fa)query(y,x,dis[x]-(dis[y]+tot[y])+d1+(n-tot[y]),n-tot[y]);
}
void answer(int x,int fa){for(auto y:nxt[x])if(y^fa)pr1(x),pr2(y),answer(y,x);}
int main()
{
	n=read();for(int i=1;i<=n;i++)D[i]=C[i]=read(),id[i]=i;
	sort(id+1,id+1+n,cmp);
	sort(C+1,C+1+n);
	for(int i=n;i>=1;i--)
	{
		int u=id[i];++siz[u];
		if(siz[u]>n)gg();if(i==1)break;
		if(2*siz[u]>=n)ins(id[1],u),ins(u,id[1]),siz[1]+=siz[u];
		else
		{
			LL nx=D[u]-(n-2*siz[u]);
			if(D[id[i-1]]<nx)gg();
			int v=lower_bound(C+1,C+1+(i-1),nx)-C;
			if(C[v]!=nx)gg();ins(id[v],u),ins(u,id[v]);siz[id[v]]+=siz[u];
		}
	}if(siz[id[1]]!=n)gg();
	getdis(1,0);query(1,0,0,0);
	answer(1,0);
	return 0;
}