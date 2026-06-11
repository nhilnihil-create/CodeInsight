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
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,k,dp[311][311][311];
char s[311];

int dfs(int l,int r,int k)
{
	if(dp[l][r][k]!=-1)return dp[l][r][k];
	if(l>r)return 0;if(l==r)return 1;
	int&ret=dp[l][r][k];
	ret=max(dfs(l,r-1,k),dfs(l+1,r,k));
	if(k||s[l]==s[r])ret=max(ret,dfs(l+1,r-1,k-(s[l]!=s[r]))+2);
	return ret;
}

int main()
{
	scanf("%s",s+1);get1(k);n=strlen(s+1);
	
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(1,n,k));
	return 0;
}