#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <iterator>
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define powr(x,n,p) for(int axy=0 ; axy<p ; axy++){x=x*n;}
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
#define nl printf("\n")
#define fr0(n,q) for(q=0 ; q<n ; q++)
#define fr1(n,q) for(q=1 ; q<=n ; q++)
#define mp make_pair
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define lst(x) x[x.size()-1]
#define llst(x) x[x.size()-2]
#define md 1000000007
#define check(x,y) (x&(1<<y))
#define set(x,y) x=x|(1<<y)
using namespace std;
int dp[3005][3005];
string s,t,ans;
int k;
int solve(int i, int j){
	if(i>=s.size() || j>=t.size()) return dp[i][j]=0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ret;
	if(s[i]==t[j]) ret=1+solve(i+1,j+1);
	else{
		ret=solve(i,j+1);
		int x=solve(i+1,j);
		if(x>ret) ret=x;
	}
	return dp[i][j]=ret;
}
void build(int i,int j){
	if(dp[i][j]<=0) return ;
	if(s[i]==t[j]){
		ans.pb(s[i]);
		build(i+1,j+1);
	}
	else{
		if(dp[i+1][j]>dp[i][j+1]) build(i+1,j);
		else build(i,j+1);
	}
}
int main()
{
	cin>>s>>t;
	int i,j;
	fr0(3005,i){
		fr0(3005,j) dp[i][j]=-1;
	}
	k=solve(0,0);
/*	for(i=0 ; i<=s.size() ; i++){
		for(j=0 ; j<=t.size() ; j++) cout<<dp[i][j]<<"   ";
		nl;
	}*/
	build(0,0);
	cout<<ans;
	nl;
	return 0;
}
