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
 	
  	ll n,k;
  	cin>>n>>k;
  
  	for(int i=0;i<n;i++)
      cin>>a[i];
  	
    ll dp[n];
  	
  	memset(dp,-1,sizeof(dp));
  	
  	dp[0]=0;
  
  	for(int i=0;i<n;i++){
      
    	for(int j=1;j<=k && i+j<n;j++){
          
          if(dp[i+j]==-1)
            dp[i+j]=dp[i]+abs(a[i+j]-a[i]);
          
          dp[i+j]=min(dp[i+j],dp[i]+abs(a[i+j]-a[i]));
        }
    }
                    
     	cout<<dp[n-1];
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
