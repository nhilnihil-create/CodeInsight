/*input
6 3
2 3
4 5
5 6
*/
 
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
 
using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define ar array
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define tests int r; cin >> r; while(r--)
#define MP make_pair
#define PI acos(-1)
typedef pair<long long, long long> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define godspeed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
 
#define M(x) ((x)%(1000000007))
 
int visited[100010];
vector<int> adj[100010];
int n;
int dp[100010];
void dfs(int node){
	visited[node] = 1;
	for(int u:adj[node]){
		if(visited[u]==0){
			dfs(u);
		}
		dp[node] = max(dp[node],dp[u]+1);
	}

}
 
 
int main() {
	godspeed;
	memset(visited,0,sizeof(visited));
	cin>>n;
	int m;
	cin>>m;
	memset(dp,0,sizeof(dp));
	rep(i,m){
		int a;
		int b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i = 1; i<=n;i++){
		if(visited[i]==0){
			dfs(i);
		}
	}
	int ma = 0;
	rep(i,n+1){
		ma = max(ma,dp[i]);
	}
	cout<<ma<<endl;



}