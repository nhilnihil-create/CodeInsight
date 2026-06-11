 #include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
string s,t;
  cin>>s>>t;
  ll S=s.size();
  ll T=t.size();
vector<vector<ll>> dp(S+1,vector<ll>(T+1));
  
  for(ll i=1;i<=S;i++) {
for(ll j=1;j<=T;j++) {
if(s[i-1]==t[j-1]) {
dp[i][j]=dp[i-1][j-1]+1;
}
  else {
dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
  }
}
  }
  
 string W;
  
 
  ll i=S;
  ll j=T;
  while(dp[i][j]!=0) {
if(s[i-1]==t[j-1]) {
W+=s[i-1];
  i--;
  j--;
}
    else if(dp[i][j-1]==dp[i][j]) {
j--;
    }
    else {
i--;
    }
  }
      

  
  reverse(all(W));
  cout<<W<<endl;
}
 
    
    
 