#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"---------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
						For(_x,L,R)cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
typedef long double LD;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=305;
int n,k;
char s[N];
int dp[N][N][N];
void ckmax(int &x,int y){
	x=max(x,y);
}
int DP(int L,int R,int k){
	if (L>R)
		return 0;
	if (L==R)
		return 1;
	if (~dp[L][R][k])
		return dp[L][R][k];
	int ans=0;
	ckmax(ans,DP(L,R-1,k));
	ckmax(ans,DP(L+1,R,k));
	if (s[L]==s[R])
		ckmax(ans,DP(L+1,R-1,k)+2);
	else if (k>0)
		ckmax(ans,DP(L+1,R-1,k-1)+2);
	return dp[L][R][k]=ans;
}
int main(){
	cin>>s+1>>k;
	n=strlen(s+1);
	memset(dp,-1,sizeof dp);
	cout<<DP(1,n,k)<<endl;
	return 0;
}