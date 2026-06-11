#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N; cin >> N;
  string S; cin >> S;
  
  ll Q; cin >> Q;
  // O(NQ)で答えられれば十分
  
  for(ll i = 0; i < Q; i++){ 
    ll k; cin >> k;
    
    ll ans = 0;
    
    ll d = 0,m = 0,dm = 0;
    
    for(ll j = 0; j < N; j++){
      
      if( j >= k ){ //除去する必要性が出てくる
        if( S[j-k] == 'D'){ d--; dm -= m;}
        if( S[j-k] == 'M'){ m--; }
      }
      
      if( S[j] == 'D'){ d++;}
      if( S[j] == 'M'){ dm += d; m++;}
      if( S[j] == 'C'){ ans += dm;}
      
    }
    
    cout << ans << endl;
    
  }
  
  return 0;
}
        
