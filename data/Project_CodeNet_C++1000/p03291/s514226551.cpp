#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
 
ll X[100100]; ll Y[100100]; ll Z[100100];

ll p(ll b){ //3のb乗
  if( b == 0){ return 1;}
  else if( b == 1){ return 3;}
  else{
    if( b % 2 == 0){ return ((p(b/2)%MOD)*(p(b/2)%MOD))%MOD;}
    else{ return (3*(p((b-1)/2)%MOD)*(p((b-1)/2)%MOD))%MOD;}
  }
}

  
  
  
int main(){
  string T; cin >> T;
  ll cnt = 0;
  for(int i = 0; i < 100100; i++){ X[i] = 0LL; Y[i] = 0LL; Z[i] = 0LL;}
  if(T[0] == 'A' || T[0] == '?'){ X[0] = 1LL;}
  if(T[0] == '?'){ cnt++;}
  
  for(int i = 0; i < (int) T.size()-1; i++){
    int flag;
    if(T[i+1] == 'A'){ flag = 1;} 
    if(T[i+1] == 'B'){ flag = 2;}
    if(T[i+1] == 'C'){ flag = 3;}
    if(T[i+1] == '?'){ flag = 4; }
    
    if( flag == 1 || flag == 4 ){ X[i+1]+=X[i]+p(cnt);Y[i+1]+=Y[i];Z[i+1]+=Z[i];}
    if( flag == 2 || flag == 4){ X[i+1]+=X[i]; Y[i+1]+=Y[i]+X[i];Z[i+1]+=Z[i];}
    if( flag == 3 || flag == 4){ X[i+1]+=X[i]; Y[i+1]+=Y[i];Z[i+1]+=Z[i]+Y[i];}
    X[i+1] %= MOD; Y[i+1] %= MOD; Z[i+1] %= MOD;
    
    if( flag == 4){ cnt++;}
    
  }
  
  cout << Z[(int)T.size()-1] << endl; return 0;}
      
      
