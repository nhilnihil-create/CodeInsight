#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
 
 ll N,K; cin >> N >> K;
 vector<ll> A(N);
 for(ll i = 0; i < N; i++){ cin >> A[i];}
 
 vector<ll> sub;
 
 for(ll l = 0; l < N; l++){
 ll sum = 0; 
  for(ll r = l; r < N; r++){
   sum += A[r];
   
   sub.push_back(sum);
   }
  }
  //ここまでOK
  
  ll m = sub.size();
  
  ll ans  = 0;
  
  vector<bool> avb(m,true);
  
  for(ll bit = 40; bit >= 0; bit--){
   //K個以上がこのフラグを立てるか調べる
   ll cnt = 0;
   for(ll i = 0; i < m; i++){
     if( ( (sub[i] >> bit) & 1 ) && avb[i]){ cnt++;}
   }
   bool flag = false;
   if( cnt >= K){ flag = true;  ans += (1LL << bit);}
   
   if(flag){
    //ここで使わなかったものを封じる
    
    for(ll i = 0; i < m; i++){
      if( !((sub[i] >> bit) & 1)){ avb[i] = false;}
     }
  }// flag-if
 } //bit-if
  
  cout << ans << endl;
  
  return 0;
}