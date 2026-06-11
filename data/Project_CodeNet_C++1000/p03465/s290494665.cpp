#include<iostream>
#include<string.h>
#include<string>
#include<bitset>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(i,u) for (register int i=head[u];i;i=sq[i].nxt)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
int n;
bitset<4002000> f;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
	n=read();
	f[0]=1;
	int sum=0;
	rep(i,1,n)
	{
		int a=read();
		f|=(f<<a);
		sum+=a;
	}
	rep(i,(sum+1)/2,sum)
		if (f[i]) {printf("%d",i);return 0;}
	return 0;
}
