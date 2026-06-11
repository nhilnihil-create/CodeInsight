#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<ll,pair<ll,char>>
#define sorted(a_1) sort(a_1.begin(),a_1.end())
#define rsorted(a_1) sort(a_1.rbegin(),a_1.rend())
#define t1(a_1) cout<<a_1<<endl;
#define t2(a_1) for(auto it_test : a_1) cout<<it_test<<" ";
#define MOD 1000000007

ll dp[100001][2];
ll topDown(vector<int>adj[],int parent, int gp, int color){
	
	if(dp[parent][color]>-1) return dp[parent][color];
	ll ways=1;
	for(auto i : adj[parent]){
		ll localways = 0;
		if(i!=gp){
			if(color==1){
				localways = topDown(adj,i,parent,1);
				localways += topDown(adj,i,parent,0);
				localways%=MOD;
			}
			else{
				localways = topDown(adj,i,parent,1);
			}
			ways*=localways;
			ways%=MOD;
		}
	}
	dp[parent][color] = ways;
	return ways;
}

void solve(){
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=0;i<n-1;i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x-1].pb(y-1);
    	adj[y-1].pb(x-1);
    }
    memset(dp,-1,sizeof(dp));
    ll ans1 = topDown(adj,0,-1,0);
    ll ans2 = topDown(adj,0,-1,1);
    t1((ans1+ans2)%MOD);

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--){
        solve();
    }

return 0;
}