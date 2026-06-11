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
int n;
int arr[100005][3],dp[100005][3];
int solve(int i, int j){
    if(i>n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ret;
    if(j==0) ret=max(arr[i][j]+solve(i+1,1),arr[i][j]+solve(i+1,2));
    else if(j==1) ret=max(arr[i][j]+solve(i+1,0),arr[i][j]+solve(i+1,2));
    else ret=max(arr[i][j]+solve(i+1,0),arr[i][j]+solve(i+1,1));
    return dp[i][j]=ret;
}
int main()
{
        sci(n);
        int i,j;
        fr0(100005,i){
            fr0(3,j) dp[i][j]=-1;
        }
        for(i=1 ; i<=n ; i++){
            for(j=0 ; j<3 ; j++) sci(arr[i][j]);
        }
        int ans=max(solve(1,0),solve(1,1));
        ans=max(ans,solve(1,2));
        printf("%d\n",ans);
    return 0;
}