#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
 
ll X[100100]; ll Y[100100]; ll Z[100100];
ll pow3(int a);
int main(){
  string T; cin >> T;
  
  for(int i = 0; i < 100100; i++){ X[i] = 0LL; Y[i] = 0LL; Z[i] = 0LL;}
  if(T[0] == 'A' || T[0] == '?'){ X[0] = 1LL;}
  int cnt=0; if(T[0] == '?')cnt++;
  for(int i = 0; i < (int) T.size()-1; i++){
    int flag;
    if(T[i+1] == 'A'){ flag = 1;} 
    if(T[i+1] == 'B'){ flag = 2;}
    if(T[i+1] == 'C'){ flag = 3;}
    if(T[i+1] == '?'){ flag = 4;}
    
    if( flag == 1 || flag == 4 ){ X[i+1]+=X[i]+pow3(cnt);Y[i+1]+=Y[i];Z[i+1]+=Z[i];}
    if( flag == 2 || flag == 4){ X[i+1]+=X[i]; Y[i+1]+=Y[i]+X[i];Z[i+1]+=Z[i];}
    if( flag == 3 || flag == 4){ X[i+1]+=X[i]; Y[i+1]+=Y[i];Z[i+1]+=Z[i]+Y[i];}
    X[i+1] %= MOD; Y[i+1] %= MOD; Z[i+1] %= MOD;
    if(flag == 4)cnt++;
  }
  
  cout << Z[(int)T.size()-1] << endl; return 0;}
      
ll pow3(int a){
  ll s=1,b=3;
  while(a){
    if(a%2){s*=b; s%=MOD;}
    b*=b; b%=MOD;
    a/=2;
  }
  return s;
}      
    
