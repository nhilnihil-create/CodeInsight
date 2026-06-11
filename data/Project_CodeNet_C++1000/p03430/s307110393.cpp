#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dp[160][160][160];
int d2[310][310][310];
string s;
int cal(int x,int y,int z){
	if(d2[x][y][z]>=0) return d2[x][y][z];
	if(x==y) return d2[x][y][z]=1;
	if(x>y) return d2[x][y][z]=0;
	int ret=0;
	if(s[x]==s[y]) ret=max(ret,cal(x+1,y-1,z)+2);
	if(z>0) ret=max(ret,cal(x+1,y-1,z-1)+2);
	ret=max(ret,cal(x+1,y,z));ret=max(ret,cal(x,y-1,z));
	return d2[x][y][z]=ret;
}
int main()
{
	int K,n,out;
	cin>>s;n=s.size();cin>>K;
	memset(dp,0,sizeof(dp));
	rep(i,n/2+1) rep(j,n/2+1) rep(k,min(K,155)+1){
		//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
		if(i<n/2) dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
		if(j<n/2) dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
		if(i<n/2 && j<n/2){
			if(s[i]==s[n-1-j]) dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+1);
			else dp[i+1][j+1][k+1]=max(dp[i+1][j+1][k+1],dp[i][j][k]+1);
		}
	}
	
	memset(d2,-1,sizeof(d2));
	//cal(0,n-1);
	
	//cout<<dp[6][9][3]<<' '<<cal(6,9)<<endl;
	rep(i,n/2+1) rep(j,n/2+1) rep(k,min(K,155)+1){
		out=max(out,dp[i][j][k]*2+cal(i,n-j-1,K-k));
	}
	cout<<out<<endl;
}
