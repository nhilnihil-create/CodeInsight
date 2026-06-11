/*
    It’s Always Darkest Before the Dawn
                This Time is that Darkness in you Life
                                                            */
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define pb push_back  
#define F first
#define S second
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
 
const ll mod=1e9+7,di=998244353,N=3e5+1;
 
bool IsQuery=false; 
ll q=1,a[N];
 
map<int,vector<int>> edge;
map<int,bool> occ;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
void solve(){
		
  	ll n;
  	cin>>n;
  
  	for(int i=1;i<=n;i++)
      cin>>a[i];
  	 
  	ll dp[n+2]={0};
  	
  	for(int i=1;i<=n;i++)
      dp[i]=INT_MAX;
  	
  	dp[1]=0;
  
  	for(int i=1;i<n;i++){
      
      dp[i+1]=min(dp[i]+abs(a[i+1]-a[i]),dp[i+1]);
      dp[i+2]=min(dp[i]+abs(a[i+2]-a[i]),dp[i+2]);
    }
    
    cout<<dp[n];
    return;   
} 
int main(){
    
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    if(IsQuery)
    cin>>q;
 
    for(int i=0;i<q;i++){
        solve();
        cout<<"\n";
    }
    return 0;
}
