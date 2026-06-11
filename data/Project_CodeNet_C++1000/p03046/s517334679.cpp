#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll M,K; cin >> M >> K;
  
  ll p = pow(2,M);
  
  if( p <= K ){ cout << -1 << endl; return 0;} 
  
  if( M == 0){
    cout << 0 << " " << 0  << endl;
  }
  else if( M == 1){ 
    if( K == 0 ){ cout << 0 << " "<< 0 << " " << 1 << " " << 1 << endl;}
    else{ cout << -1 << endl;}
  }
  else{
    //具体的に構成
    
    vector<ll> b;
    
    for(ll i = 0; i < p; i++){
      if( i == K){ continue;}
      b.push_back(i);
    }
    
    vector<ll> c = b;
    
    reverse(c.begin(),c.end());
    
    for(auto ne : b){ cout << ne << " ";}
    cout << K << " ";
    for(auto ne : c){ cout << ne << " ";}
    cout << K << endl;
    

  }
  return 0;
} 