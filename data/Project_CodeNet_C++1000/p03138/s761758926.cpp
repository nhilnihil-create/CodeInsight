#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N);
  for(int i(0);i<N;i++) cin>>A[i];
  bool flag = false,small_flag = false;
  ll ans(0),x(0),tmp(1);
  for(int i(0);i<40;i++){
    tmp *= 2; 
  }
  for(int i(40);i>=0;i--){
    if(!flag && ((K >> i) & 1)) flag = true; 
    if(flag){
      int cnt0(0),cnt1(0);
      for(int j(0);j<N;j++){
        if((A[j] >> i) & 1) cnt1++; 
        else cnt0++;
      }
      //cout << cnt0 << " " << cnt1 << " " << small_flag <<" " <<x <<  endl;
      if(cnt0 > cnt1){
        if(!((K >> i) & 1) && small_flag == false){
        }else{
          x += tmp;
        }
      }else if(((K >> i) & 1)){
        small_flag = 1;
      }
    }
    tmp /= 2;
  }
  //cout << x << endl;
  for(int i(0);i<N;i++){
    ans += A[i] ^ x;
  }
  cout << ans << endl;
  return 0;
}
