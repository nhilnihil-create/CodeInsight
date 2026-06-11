#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

int main(){
  string S;
  ll K;
  cin >> S >> K;
  rep(i,(ll)S.size()){
    if(S.at(i)=='1'){
      if(K==i+1){
        cout << 1 << endl;
        return 0;
      }
    }else{
      cout << S.at(i) << endl;
      return 0;
    }
  }
}
          
      