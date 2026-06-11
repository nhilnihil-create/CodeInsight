#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll N,Y;
  cin >> N >> Y;
  Y/=1000;
  rep(i,N+1){
    rep(j,N+1){
      if(i+5*j<=Y&&(Y-i-5*j)%10==0&&i+j+(Y-i-5*j)/10==N){
        cout << (Y-i-5*j)/10 << " " << j << " " << i << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}
  
  