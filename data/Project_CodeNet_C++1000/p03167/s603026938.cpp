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
string arr[3005];
int dp[3005][3005];
int h,w;
int solve(int i, int j){
	if(i==h-1 && j==w-1) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	int ret=0;
	if(i+1<h && arr[i+1][j]=='.') ret+=solve(i+1,j);
	if(j+1<w && arr[i][j+1]=='.') ret+=solve(i,j+1);
	return dp[i][j]=(ret%md);
}
int main()
{
	cin>>h>>w;
	for(int i=0 ; i<3005 ; i++){
		for(int j=0 ; j<3005 ; j++) dp[i][j]=-1;
	}
	for(int i=0 ; i<h ; i++) cin>>arr[i];
	cout<<solve(0,0);
	nl;
	return 0;
}
