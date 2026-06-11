#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
#define Fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define f(i, n) for (long long int i = 0; i < n; i++)
#define ll long long int
#define fo(i, a, b) for (long long int i = a; i <= b; i++)
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define newl cout<<"\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll inf = 1e9 + 7;
const ll modc = 998244353;
#define MAX 100002

int vis[MAX];
int dp[MAX];
vi adj[MAX];

void dfs(int node){
	vis[node] = 1;
	dp[node] = 0;
	for(auto child: adj[node]){
		if(!vis[child])dfs(child);
		dp[node] = max(dp[node],1+dp[child]);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	f(i,m){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
	}
	fo(i,1,n){
		if(!vis[i])dfs(i);
	}
	int ans = 0;
	fo(i,1,n)ans = max(ans,dp[i]);
	cout<<ans;
}