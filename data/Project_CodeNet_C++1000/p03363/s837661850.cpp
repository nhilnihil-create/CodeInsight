#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;cin >> N;
  vector<ll> S(N+1,0);
  for(int i=0;i<N;i++){
    ll a;cin >> a;
    S[i+1] = S[i] + a;
    //cout << S[i+1] << " ";
  }
  //cout << endl;
  sort(S.begin(),S.end());
  ll sum=0;
  ll i=0;
  for(ll j=0;j<=N;j++){
    if(j==N){
      sum += (j-i)*(j-i+1)/2;
    }else if(S[j]!=S[j+1]){
      sum += (j-i)*(j-i+1)/2;
      //cout << j << " " << sum << endl;
      i = j + 1;
    }
  }
  cout << sum << endl;
}