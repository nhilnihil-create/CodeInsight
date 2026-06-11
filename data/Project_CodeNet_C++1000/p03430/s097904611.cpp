#include<bits/stdc++.h>
#define eps 1e-8
#define pi 3.14159265358979
#define LL long long
#define MP make_pair
#define PH push
#define PB push_back
#define PII pair<int,int>
#define VI vector<int>
#define X first
#define Y second
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define sqr(x) ((x)*(x))
#define CL(a) memset(a,0,sizeof a)
#define fr(i,n) for(int i=1;i<=n;i++)
#define FR(i,S,n) for(int i=S;i<=n;i++)
#define dr(i,n) for(int i=n;i;i--)
#define DR(i,n,S) for(int i=n;i>=S;i--)
#define SZ(x) ((int)(x).size())
#define rd(x) scanf("%d",&x)
#define pr(x) printf("%d",x)
const int N=305;
LL Pw(LL a,LL b,LL p){LL v=1;for(;b;b>>=1,a=a*a%p)if(b&1)v=v*a%p;return v;}
using namespace std;
int n,m,f[N][N][N];char s[N];bool v[N][N][N];
int dp(int l,int r,int k){
	if(k<0)return -1e9;
	if(l>r)return 0;
	if(l==r)return 1;
	if(v[l][r][k])return f[l][r][k];v[l][r][k]=1;
	int an=max(dp(l+1,r,k),dp(l,r-1,k));
	an=max(an,dp(l+1,r-1,k-(s[l]!=s[r]))+2);
	return f[l][r][k]=an;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);rd(m);
	printf("%d\n",dp(1,n,m));
}