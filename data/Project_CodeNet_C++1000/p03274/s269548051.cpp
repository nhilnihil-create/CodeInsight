#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,K;
  cin >> N >> K;
  vector<ll> X(N);
  for(int i=0;i<N;i++){
    cin >> X[i];
  }
  ll ans=1e9;
  for(int i=0;i<=N-K;i++){
    if(X[i]*X[i+K-1]<0){
      ans=min(ans,min(2*abs(X[i])+X[i+K-1],abs(X[i])+2*X[i+K-1]));
    }
    else{
      ans=min(ans,max(abs(X[i]),abs(X[i+K-1])));
    }
  }
  cout << ans << endl;
}