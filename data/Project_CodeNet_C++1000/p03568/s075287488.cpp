#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i(0);i<N;i++) cin>>A[i];
  ll ans(pow(3,N));
  ll tmp(1);
  for(int i(0);i<N;i++){
    if(A[i]%2==0) tmp *= 2;
  }
  cout << ans - tmp << endl;
  return 0;
}
