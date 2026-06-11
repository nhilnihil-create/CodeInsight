#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=5050;
LL dp[M][M];
int n,A,B,a[M],pos[M];
int val(int x,int d){
	if (2*pos[x]<d) return A;
	if (2*pos[x]>d) return B;
	return 0;
}
int main(){
	n=read(); A=read(); B=read();
	F(i,1,n) a[i]=read(),pos[a[i]]=i;
	ms(dp,1); dp[0][0]=0;
	F(i,0,n){
		F(j,0,n){
			if (i) dp[i][j]=min(dp[i][j],dp[i-1][j]);
			if (j) dp[i][j]=min(dp[i][j],dp[i][j-1]+val(j,2*i+1));
			if (i&&j) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+val(j,2*i));
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<"   ouoh\n";
		}
	}
	cout<<dp[n][n]<<"\n";
    return 0;
}

