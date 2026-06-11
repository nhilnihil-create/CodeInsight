//すぬけ見ました
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n,x;
  cin >> n >> x;
  vector<tuple<ll,ll,ll>>a(n),b(n),c(n);
  for(int i=0; i<n; i++){
    cin >> get<1>(a[i]) >> get<2>(a[i]) >> get<0>(a[i]);
  }
  sort(a.begin(),a.end());
  
  ll j=1;
  for(int i=1; i<n; i++){
    if(get<0>(a[i])!=j){
      j++;
      continue;
    }
    
    if(get<1>(a[i])==get<2>(a[i-1])){
      get<1>(a[i])=get<1>(a[i-1]);
      get<0>(a[i-1])=0;
    }
  }
  
  vector<ll>count(100005);
  for(int i=0; i<n; i++){
    if(get<0>(a[i])==0) continue;
    count[get<1>(a[i])]++;
    count[get<2>(a[i])+1]--;
  }
  
  vector<ll>dp(100005);
  dp[0]=count[0];
  for(int i=1; i<100005; i++){
    dp[i]=dp[i-1]+count[i];
    
  }

  ll ans=0;
  for(int i=0; i<100005; i++){
    ans=max(ans,dp[i]);
  }
  cout << ans << endl;
}
  
  
  
