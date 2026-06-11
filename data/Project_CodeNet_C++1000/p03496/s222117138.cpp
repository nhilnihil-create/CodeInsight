#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll INF = 1LL << 60;
ll itr_M = 0; ll itr_m = 0;

void chmax(ll &a, ll b, ll c){ if( a < b){ swap(a,b); itr_M = c;} return ;}

void chmin(ll &a, ll b, ll c){ if( a > b){ swap(a,b); itr_m = c;} return ;}

int main(){
  ll N; cin >> N;
  vector<ll> A(N); 
  ll max_A = -INF; ll min_A = INF;

  for(ll i = 0; i < N; i++){ 
    cin >> A[i]; chmax(max_A,A[i],i); chmin(min_A,A[i],i);}
  
  if( max_A == min_A){ cout << 0 << endl; return 0;}
  
  if( abs(max_A) >= abs(min_A)){
    cout << 2*N-2 << endl;
    for(ll i = 0; i < N; i++){
      if( i == itr_M){ continue;}
      cout << itr_M+1 << " " << i+1 << endl;}
    for(ll i = 0; i < N-1; i++){
      cout << i+1 << " " << i+2 << endl;}
    
  }
  
  else{
    cout << 2*N-2 << endl;
    for(ll i = 0; i < N; i++){
      if( i == itr_m){ continue;}
      cout << itr_m+1 << " "<< i+1 << endl;}
    for(ll i = N-1; i >= 1; i--){
      cout << i+1 << " " << i << endl;}
    
  }
  
  return 0;}
    
  
   