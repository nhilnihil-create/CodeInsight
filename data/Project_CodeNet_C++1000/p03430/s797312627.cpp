#include<bits/stdc++.h>
#define LL long long 
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=a;i<=b;i++)
#define DF(i,a,b) for (int i=a;i>=b;i--)
#define SZ(x) (int)x.size()-1
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=333;
int dp[M][M][M];
char s[M];
int n,k;
int solve(int x,int y,int l){
	if (dp[x][y][l]) return dp[x][y][l];
	if (l<0) return -1e9;
	if (x>y) return 0;
	if (x==y) return dp[x][y][l]=1;
	dp[x][y][l]=max(solve(x+1,y-1,l-(s[x]!=s[y]))+2,max(solve(x+1,y,l),solve(x,y-1,l)));
	return dp[x][y][l];
} 
int main(){
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	cout<<solve(1,n,k)<<"\n";
	return 0;
} 