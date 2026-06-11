#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;



int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll>a(26,1);
  for(int i=0; i<n; i++){
    a[s[i]-'a']++;
  }
  
  //for(int i=0; i<26; i++) cout << a[i] << endl;
  
  ll ans = 1;
  for(int i=0; i<26; i++){
    ans*=a[i];
    ans%=mod;
  }
  
  cout << ans-1 << endl;
  
}
       
        
      
  
    
