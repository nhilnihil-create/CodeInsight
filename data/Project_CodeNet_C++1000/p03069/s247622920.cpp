#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;



int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  
  vector<ll>b(n),w(n);
  
  for(ll i=0; i<n; i++){
    if(s[i]=='#'){
      break;
    }
    s[i]='0';
  }
  
  for(ll i=n-1; i>=0; i--){
    if(s[i]=='.'){
      break;
    }
    s[i]='0';
  }
  
  for(ll i=1; i<n; i++){
    if(s[i]=='.')w[0]++;
  }
  
  ll ans = w[0];
  
  for(ll i=1; i<n; i++){
    w[i]=w[i-1];
    b[i]=b[i-1];
    if(s[i]=='.') w[i]--;
    if(s[i-1]=='#') b[i]++;
    ans = min(ans,b[i]+w[i]);
    //cout << ans << endl;
    
  }
  
  
  //for(int i=0; i<n; i++)cout << s[i];
  //cout << w[0] << endl;
  
  cout << ans << endl;
  
  
  
  
}
       
        
      
  
    