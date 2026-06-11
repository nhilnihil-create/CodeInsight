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
int dp[100005];
int arr[100005];
int n;
int solve(int x){
	if(x>=n) return 0;
	if(dp[x]!=-1) return dp[x];
	int ret;
	if(x==n-1) ret=abs(arr[x+1]-arr[x])+solve(x+1);
	else ret=min(abs(arr[x+1]-arr[x])+solve(x+1),abs(arr[x+2]-arr[x])+solve(x+2));
	return dp[x]=ret;
}
int main()
{
	int i;
	cin>>n;
	for(i=0 ; i<100005 ; i++) dp[i]=-1;
	for(i=1 ; i<=n ; i++) cin>>arr[i];
	cout<<solve(1);
	nl;
	return 0;
}
