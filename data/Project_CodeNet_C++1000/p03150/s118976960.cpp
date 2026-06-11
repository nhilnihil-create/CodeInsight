#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  string S,T;
  cin >> S;
  T="keyence";
  rep(i,7){

    ll j=0,t=0;
    while(j<i){
      if(S.at(j)!=T.at(t)){
        goto NEXT;
      }else{
        j++;
        t++;
      }
    }
    j+=S.size()-7;
    while(j<S.size()){
      if(S.at(j)!=T.at(t)){
        goto NEXT;
      }else{
        j++;
        t++;
      }
    }
    cout << "YES" << endl;
    return 0;
    NEXT:
    continue;
  }
  cout << "NO" << endl;
    
}