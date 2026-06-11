#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f(a, b) for (ll i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define mp make_pair
using namespace std;
#define N 100005
const ll INF = 1000000001;
const ll MOD = 998244353 ; //1e9+7;
 
using namespace std;
vector<int> adj[100001];
bool visited[100001];
int dp[100001];
void intialize(){
    for(int i=0;i<100001;i++){
        visited[i]=0;
    }
}
void dfs(int s){
    visited[s]=1;
    for(auto u:adj[s]){
        if(visited[u]==0){
            //dp[]
            dfs(u);
        }
        dp[s]=max(dp[s],1+dp[u]);
    }
    //int ans=INT_MIN;
   // for(int i=1;i<=n;i++){
        //ans=max(ans.dp[i]);
    //}
    //return ans;

}

int main() {
   int n,m,x,y,connected=0;
   cin>>n>>m;
   for(int i=0;i<m;i++){
   cin>>x>>y;
   adj[x].push_back(y);
   }
   intialize();
   for(int i=1;i<=n;i++){
       if(visited[i]==0){
           dfs(i);
           //connected++;
       }
   }
   int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
  

}
