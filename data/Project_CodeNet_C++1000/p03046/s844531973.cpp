#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1000000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll M,K;
  cin >> M >> K;
  if(M==0){
    if(K==0) cout << "0 0" << endl;
    else cout << -1 << endl;
  }else if(M==1){
    if(K==0) cout << "0 0 1 1" << endl;
    else cout << -1 << endl;
  }else{
    if((ll)pow(2,M)<=K) cout << -1 << endl;
    else{
      rep(i,(ll)pow(2,M)){
        if(i!=K) cout << i << " ";
      }
      cout << K << " ";
      for(ll i=(ll)pow(2,M)-1;i>=0;i--){
        if(i!=K) cout << i << " ";
      }
      cout << K << endl;
    }
  }
}