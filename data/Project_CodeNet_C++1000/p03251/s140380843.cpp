#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M,X,Y;cin>>N>>M>>X>>Y;
 vector<ll> x(N);
  for(ll i=0;i<N;i++) {
cin>>x[i];
  }
  vector<ll> y(M);
  for(ll i=0;i<M;i++) {
    cin>>y[i];
  }
  
  sort(all(x));
  sort(all(y));
  
  ll xmax=x.back();
  ll ymin=y[0];
  
  if(X<=xmax&&xmax<ymin&&ymin<=Y) {
cout<<"No War"<<endl;
  }
  else {
cout<<"War"<<endl;
  }
}
  
  