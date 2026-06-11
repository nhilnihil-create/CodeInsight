#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,ans=0;
  cin >> N;
  for(ll i=1;i*i<N;i++){
    if((N-i)%i==0){
      ll k=(N-i)/i;
      if(N/k==N%k){
        ans+=k;
      }
    }
  }
  cout << ans << endl;
}