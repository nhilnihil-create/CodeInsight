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
		
  	string s,t,ans;
  	
  	cin>>s>>t;
  	
  	int dp[3001][3001]={0};
  
  	for(int i=1;i<=(int)s.size();i++){
      
      for(int j=1;j<=(int)t.size();j++){
        
        	if(s[i-1]==t[j-1])
          	dp[i][j]=dp[i-1][j-1]+1;
        	
        	else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }      
    }
  	
  	int r=s.size(),c=t.size();
  
  	while(dp[r][c]>0){
      	
      	if(s[r-1]==t[c-1]){
          ans.push_back(s[r-1]);
          r--,c--;
        }
      
      	else if(dp[r-1][c]>dp[r][c-1])
          r--;
      	
      	else
          c--;
    }
  	reverse(all(ans));
  
  	cout<<ans;
  
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