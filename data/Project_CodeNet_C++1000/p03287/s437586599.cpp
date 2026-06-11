#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N,M;cin >> N >> M;
  vector<ll> A(N,0);
  vector<ll> B(N+1,0);
  for(int i=0;i<N;i++){
    cin >> A[i];
    B[i+1] = (A[i]+B[i])%M;
  }
  sort(B.begin(),B.end());
  ll sum = 0;
  ll i = 0;
  for(int j=0;j<=N;j++){
    if(j==N){
      ll x = j - i + 1;
      sum += x*(x-1)/2;
      cout << sum << endl;
      return 0;
    }
    if(B[j]!=B[j+1]){
      ll x = j - i + 1;
      sum += x*(x-1)/2;
      i = j + 1;
    }
  }
}