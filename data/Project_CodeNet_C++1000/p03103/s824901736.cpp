#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll N,M;
  cin>>N>>M;
  vector<vector<ll>>vec(N,vector<ll>(2));
  for(ll i=0;i<N;i++){
    cin>>vec.at(i).at(0)>>vec.at(i).at(1);
  }
  sort(vec.begin(),vec.end());
  ll a=0;
  for(ll i=0;i<N;i++){
    if(M>vec.at(i).at(1)){
      a+=vec.at(i).at(1)*vec.at(i).at(0);
      M-=vec.at(i).at(1);
    }
    else{
      a+=vec.at(i).at(0)*M;
      cout<<a<<endl;
      return 0;
    }
  }
}

