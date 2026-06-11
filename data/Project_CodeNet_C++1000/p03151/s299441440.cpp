#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int N,ans=0;
  cin >> N;
  vector<ll> A(N),B(N),diff;
  ll sum=0;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
    if(A[i] >= B[i]) diff.push_back(A[i]-B[i]);
    else{
      sum += B[i] - A[i];
      ans++;
    }
  }
  sort(diff.begin(), diff.end());
  reverse(diff.begin(), diff.end());
  int flag=0;
  if(sum == 0) ans = 0;
  else{
    for(int i=0; i<diff.size(); i++){
      sum -= diff[i];
      ans++;
      if(sum <= 0) {flag = 1; break;}
    }
    if(flag == 0) ans = -1;
  }  
  cout << ans;
  return 0;
}