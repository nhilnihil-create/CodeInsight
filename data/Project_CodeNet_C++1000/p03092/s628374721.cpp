#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=5005;
const ll inf=1e18;
ll dp[N][N];
int p[N],A,B,to[N];
int main(){
	int n=read(); A=read(); B=read();
	for(int i=1;i<=n;i++){
		p[i]=read(); to[p[i]]=i;
	}
	ll ans=inf;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(p[i+1]<=j)dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			if(to[j+1]<=i)dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
			if(p[i+1]==j+1)dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+A);
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+B);
		}
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)if(max(i,j)==n)ans=min(ans,dp[i][j]);
	cout<<ans<<endl;
}
/*
位置<i 或者 <=j的数已经归位 
*/