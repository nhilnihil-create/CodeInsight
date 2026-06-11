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
 	
  	ll n,a[3];
  	
  	cin>>n;
  	
  	ll dp[n+1][3];
  	
  	memset(dp,0,sizeof(dp));
  
  	for(int i=1;i<=n;i++){
		
      	cin>>a[0]>>a[1]>>a[2];
      
      	dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[0];
      	dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[1];
      	dp[i][2]=max(dp[i-1][0],dp[i-1][1])+a[2];
    }
  
  	cout<<max(max(dp[n][0],dp[n][1]),dp[n][2]);
  
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
