#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int M=50;
const int N=1010;
int x[N],y[N];
int abs(int x)
{
	return x>0?x:-x;
}
int t;
int d[M];
char ans[N][M];
int n;
void gao(int k)
{
	t++;
	d[t]=k;
	for(int i=1;i<=n;i++)
		if(abs(x[i])>abs(y[i]))
		{
			if(x[i]>0)
			{
				x[i]-=k;
				ans[i][t]='R';
			}
			else
			{
				x[i]+=k;
				ans[i][t]='L';
			}
		}
		else
		{
			if(y[i]>0)
			{
				y[i]-=k;
				ans[i][t]='U';
			}
			else
			{
				y[i]+=k;
				ans[i][t]='D';
			}
		}
}
int main()
{
	//open2("d");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=30;i>=1;i--)
	{
		int k=(1<<i);
		bool tf=false;
		for (int u=1;u<=n;u++)
		{
			if (abs(x[u])>k) tf=true;
			if (abs(y[u])>k) tf=true;
		}
		if (tf)	gao(k);
		tf=false;
		for (int u=1;u<=n;u++)
		{
			if (abs(x[u])>k) tf=true;
			if (abs(y[u])>k) tf=true;
		}
		i=i+tf;
	}
	//for (int u=1;u<=n;u++) printf("%d %d\n",x[u],y[u]);
	int tt=t;
	for(int i=1;i<=39-tt;i++)
		gao(1);
	if(x[1]||y[1])
		gao(1);
	//for (int u=1;u<=n;u++) printf("%d %d\n",x[u],y[u]);
	for(int i=1;i<=n;i++)
		if(x[i]||y[i])
		{
			printf("-1\n");
			return 0;
		}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d ",d[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%s\n",ans[i]+1);
	return 0;
}