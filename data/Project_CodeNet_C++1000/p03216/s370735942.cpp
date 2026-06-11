#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1000010;

int main(){
  ll N; cin >> N;
  string S; cin >> S;
  
  ll Q; cin >> Q;
  
  for(ll i = 0; i < Q; i++){
    
    ll k; cin >> k;
    
    ll ans = 0;
    
    ll d = 0; ll dm = 0; ll m = 0;
    
    for(ll j = 0; j < N; j++){
      
      if(j-k >= 0){ //これ違うかも
        if( S[j-k] == 'D'){ d--; dm -= m;}
        if( S[j-k] == 'M'){ m--;}
      }
      
      if( S[j] == 'D'){ //使えるDを増やす
        d++;}
      if( S[j] == 'M'){ m++; //mを増やす
                       dm += d; //dm数は、今使えるdの数だけ増える
                      }
      if( S[j] == 'C'){ ans += dm;
                      }
         
         }
    
    cout<< ans << endl;
  }
  
  return 0;
}
     