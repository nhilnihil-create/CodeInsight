#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=5e3+20;
const ll inf=1ll<<60;

int n,A,B;
int p[maxn];
ll dp[maxn];
int s[maxn][maxn];

inline void init()
{
	n=read();A=read();B=read();
	REP(i,1,n)p[i]=read(); p[n+1]=n+1; 
	REP(i,1,n+1)s[i][p[i]]++;
	REP(i,1,n+1)REP(j,1,n+1)s[i][j]+=s[i][j-1];
	REP(i,1,n+1)REP(j,1,n+1)s[i][j]+=s[i-1][j];
}

inline int Matrix(int x1,int x2,int y1,int y2)
{
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

inline void doing()
{
	dp[0]=0;
	REP(i,1,n+1)
	{
		dp[i]=inf;
		REP(j,0,i-1)if(p[j]<p[i])
		{
			int num=Matrix(j+1,i-1,p[j]+1,p[i]-1);
			if(!num)
			{
				int a=Matrix(j+1,i-1,p[i]+1,n+1);
				int b=Matrix(j+1,i-1,1,p[j]-1);
				chkmin(dp[i],(ll)a*A+(ll)b*B+dp[j]);
			}
		}
	}
	printf("%lld\n",dp[n+1]);
}

int main()
{
	init();
	doing();
	return 0;
}
