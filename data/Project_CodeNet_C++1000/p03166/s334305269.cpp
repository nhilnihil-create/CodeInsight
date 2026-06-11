#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define unmap  	unordered_map<int,int>
#define	unset	unordered_set<int>
#define maxpq  	priority_queue<int>
#define minpq  	priority_queue<int, vector<int>, greater<int>>
#define pb 		push_back		
#define ll 		long long
#define ull     unsigned ll
#define ff 		first
#define ss 		second//typedef second ss;
#define foton(i,n) for(int i=0;i<n;i++)
#define	faton(i,a,n)	for(int i=a;i<=n;i++)
#define mod 	1000000007
#define endl "\n"
using namespace std;

void solve(){
	
}
vector<ll> adj[100001];
bool vis[100001];
ll t[100001];

ll dfs(ll node){
    if(vis[node]){
        return t[node];
    }
    vis[node] = true;
    ll maxi = 0;
    for(auto x : adj[node]){
            maxi = max(maxi,1+dfs(x));
    }
    return t[node] = maxi;
}

int main(){
	fastio;
	ll n,m,a,b;
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        cin>>a>>b,  adj[a].pb(b);
    }
    memset(vis,false,sizeof(vis));
    memset(t,0,sizeof(t));
    ll maxi = 0;
    for(ll i=1;i<=n;i++){
        if(vis[i] == 0){
            maxi = max(maxi,dfs(i));
        }
    }
    cout<<maxi<<endl;
	return 0;
}