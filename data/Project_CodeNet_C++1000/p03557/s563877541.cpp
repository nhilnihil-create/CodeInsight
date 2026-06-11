#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N),B(N),C(N);
  for(ll i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(ll i=0;i<N;i++){
    cin >> B.at(i);
  }
  for(ll i=0;i<N;i++){
    cin >> C.at(i);
  }  
  
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  
  ll ans=0;
  /*
  for(ll i=0;i<N;i++){
    ll b = B.at(i);
    ans += (lower_bound(A.begin(),A.end(),b)-A.begin()) * (C.end() - upper_bound(C.begin(),C.end(),b));
  }
  */
  
  for(int i=0;i<N;i++){
    ans += (lower_bound(A.begin(), A.end(), B[i]) - A.begin())
        * (C.end() - upper_bound(C.begin(), C.end(), B[i]));
  }  

  cout << ans << endl;
  
  return(0);
}