// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=0x3f3f3f3f3f3f3f3fll;
const double pi=acos(-1.0);

const int maxn=5111;

int n,a,b,p[maxn];
LL dp[maxn][maxn];
inline void upd(LL&x,LL y){if(x>y)x=y;}

int main()
{
	get3(n,a,b);
	for(int i=1;i<=n;i++)get1(p[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)
	{
		//go left
		upd(dp[i+1][max(j,p[i])],b+dp[i][j]);
		//stay
		if(p[i]>j)upd(dp[i+1][max(j,p[i])],dp[i][j]);
		//go right
		if(p[i]>j)upd(dp[i+1][j],dp[i][j]+a);
	}
	LL ans=Linf;
	for(int j=0;j<=n;j++)ans=min(ans,dp[n+1][j]);
	printendl(ans);
	return 0;
}