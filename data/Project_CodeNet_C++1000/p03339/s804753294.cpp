#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N;string S;cin >> N >> S;
  vector<ll> ac(N);
  ac[0] = ((S[0]=='E') ? 1 : 0);
  for(ll i=1;i<N;++i){
    ac[i] = ac[i-1] + ((S[i]=='E') ? 1 : 0);
  }
  ll ans = 1e9;
  rep(i,N){
    if(i==0) ans = min(ans,ac[N-1]-ac[0]);
    else ans = min(ans,(i-ac[i-1])+(ac[N-1]-ac[i]));
  }
  cout << ans << endl;
}