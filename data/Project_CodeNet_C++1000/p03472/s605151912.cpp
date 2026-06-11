#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<ll,ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()


int main(){
  ll N,H,ans=0;
  cin >> N >> H;
  vec A(N),B(N);
  rep(i,N){
    cin >> A.at(i) >> B.at(i);
  }
  sort(all(A));
  sort(all(B));
  rep(i,N){
    if(B.at(N-1-i)>A.at(N-1)){
      H-=B.at(N-1-i);
      ans++;
      if(H<=0){
        cout << ans << endl;
        return 0;
      }
    }else{
      break;
    }
  }
  ans+=(H-1)/A.at(N-1)+1;
  cout << ans << endl;
        
}
          
         