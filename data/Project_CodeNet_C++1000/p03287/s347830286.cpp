#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,m;
  cin>>n>>m;

  map<ll,ll> M;
  ll tmp=0,x;
  M[0]++;
  rep(i,n){
    cin>>x;
    tmp=(tmp+x)%m;
    M[tmp]++;
  }
  
  ll sum=0;
  for(auto y:M){
    if(y.second<2) continue;
    sum+=y.second*(y.second-1)/2;
  }
  cout<<sum<<endl;

  return 0;
}