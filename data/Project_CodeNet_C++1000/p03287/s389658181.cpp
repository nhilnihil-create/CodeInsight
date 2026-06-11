#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,M,m=0,ans=0;
  cin >> N >> M;
  vector<ll> A(N);
  map<ll,ll> B;
  B[0]=1;
  rep(i,N){
    cin >> A.at(i);
    m+=A.at(i);
    m%=M;
    if(B.count(m)){
      B.at(m)++;
    }else{
      B[m]=1;
    }
  }
  for(auto p:B) {
    auto key = p.first;
    auto value = p.second;
    ans+=value*(value-1);
  }
  ans/=2;
  cout << ans << endl;
}
      