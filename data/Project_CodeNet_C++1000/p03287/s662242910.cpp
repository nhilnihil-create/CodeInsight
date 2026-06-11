#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  ll N,M;cin>>N>>M;
  vll A(N);rep(i,N)cin>>A[i];
  vll cumsum(N+1,0);
  cumsum[0]=0;
  rep(i,N){
    cumsum[i+1]=cumsum[i]+A[i];
  }
  map<int,int> m;
  rep(i,N+1){
    m[cumsum[i]%M]++;
  }
  ll ans=0;
  for(auto& x:m){
    ans += ll(x.second)*ll(x.second-1)/2;
  }
  cout << ans << endl;
}