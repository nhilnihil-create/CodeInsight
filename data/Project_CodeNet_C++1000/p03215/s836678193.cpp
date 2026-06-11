#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
  ll N,K; cin >> N >> K;
  vector<ll> A(N);
  for(int i = 0; i < N; i++){ cin >> A[i];}
  
  vector<ll> vec; 
  
  for(ll i = 0; i < N; i++){
    ll res = A[i];
    for(ll j = i; j < N; j++){ // A[i]+,,+A[j]を求めたい
      
      if(j > i){ res += A[j];}
      
      vec.push_back(res);
    }
    
  }
 
  ll ans = 0;
  
  for(ll i = 45; i >= 0; i--){
    
    int cnt = 0;
   
    for(auto ne : vec){
      // ansに含まれるbitが全てneに含まれるためには、orをとったものがneに等しければいい
      
      if( ( ( ne >> i) & 1 ) && ( ans | ne ) == ne){  cnt++;
                    }
    }
    
    if( cnt >= K){ ans |= 1LL << i;}
  }
  
  cout << ans << endl;
  
  return 0;
}