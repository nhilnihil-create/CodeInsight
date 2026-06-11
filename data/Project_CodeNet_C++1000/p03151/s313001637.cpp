#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N),B(N);
  for(int i(0);i<N;i++) cin>>A[i];
  for(int i(0);i<N;i++) cin>>B[i];
  ll suma(0),sumb(0);
  for(int i(0);i<N;i++){
    suma += A[i];
    sumb += B[i];
  }
  if(suma < sumb){
    cout << "-1" << endl;
    return 0;
  }
  ll tarinai_sum(0),cnt_tarinai(0);
  for(int i(0);i<N;i++){
    if(A[i] < B[i]){
      tarinai_sum += (B[i] - A[i]);
      cnt_tarinai++;
    } 
  }
  //cout << cnt_tarinai <<" " << tarinai_sum<< endl;
  vector<ll> yobun;
  for(int i(0);i<N;i++){
    if(A[i] > B[i]){
      yobun.push_back(A[i]-B[i]);
    }
  }
  sort(yobun.rbegin(),yobun.rend());
  ll cnt(0);
  ll tmp(0);
  for(int i(0);i<int(yobun.size());i++){
    if(tmp >= tarinai_sum){
      cout << cnt_tarinai + cnt << endl;
      return 0;
    }
    tmp += yobun[i];
    cnt++;
  //  cout << tarinai_sum << " " << cnt << endl;
  }
  if(tmp >= tarinai_sum){
    cout << cnt_tarinai + cnt << endl;
    return 0;
  }
  return 0;
}
