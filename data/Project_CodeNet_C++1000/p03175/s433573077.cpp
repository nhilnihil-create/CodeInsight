#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<long long int>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vb vector<bool>
#define vvl vector<vector<ll> >
#define vvi vector<vector<int> >
#define pl pair<ll,ll>
#define pb push_back
#define PI 3.14159265
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fri(s,n) for(int i=s;i<n;i++)
#define frj(s,n) for(int j=s;j<n;j++)
#define T(i) int i=1;cin>>i;while(i--)
#define vsi vector<set<int> >
#define pii pair<int,int>
#define inf 1e9
#define vpii vector<pair<int,int> >


ll power(ll a,ll b){
    if(b==0)
        return 1;
    if(b&1)
        return a*power(a,b-1);
    ll temp=power(a,b/2);
    return temp*temp;
    }
bool mycompare(ll a,ll b){
    return a>b;
    }
ll dp[100005][2];
vector<vector<int> > graph;
ll solve(vector<vector<int> >& graph,int parent,int node,int col){
  	if(dp[node][col]!=-1)
      	return dp[node][col];
    dp[node][col]=1;
  	for(auto nbr:graph[node]){
      	if(nbr!=parent){
        	if(col)
                dp[node][col]=dp[node][col]*(solve(graph,node,nbr,0)+solve(graph,node,nbr,1)%mod)%mod;
            else
                dp[node][col]=dp[node][col]*solve(graph,node,nbr,1)%mod;
        }
    }
    return dp[node][col];
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  	int n;
  	cin>>n;
  	memset(dp,-1,sizeof dp);
    graph.resize(n+1);
  	for(int i=0;i<n-1;i++){
      	int x,y;
      	cin>>x>>y;
    	graph[x].push_back(y);
      	graph[y].push_back(x);
    }
  	cout<<(solve(graph,0,1,1)%mod+solve(graph,0,1,0)%mod)%mod;

	}

