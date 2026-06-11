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
vector<int> nxt[MAXN];
void ins(int x,int y){nxt[x].emplace_back(y);}
int otA[MAXN],otB[MAXN],vis[MAXN],n,m;
char ch[MAXN];
queue<int> li;
int main()
{
	n=read();m=read();
	scanf("%s",ch+1);
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);
		if(ch[x]=='A')otA[y]++;else otB[y]++;
		if(ch[y]=='A')otA[x]++;else otB[x]++;
	}
	for(int i=1;i<=n;i++)if(!otA[i]||!otB[i])vis[i]=1,li.push(i);
	while(!li.empty())
	{
		int x=li.front();li.pop();vis[x]=1;
		for(auto y:nxt[x])if(!vis[y])
		{
			if(ch[x]=='A')--otA[y];else --otB[y];
			if(!otA[y]||!otB[y])vis[y]=1,li.push(y);
		}
	}bool flag=false;
	for(int i=1;i<=n;i++)flag|=(!vis[i]);
	puts(flag?"Yes":"No");
	return 0;
}

