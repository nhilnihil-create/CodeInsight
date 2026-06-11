#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N;cin>>N;
  vector<ll> C(N),S(N),F(N);rep(i,N-1)cin>>C[i]>>S[i]>>F[i];
  vector<ll> ans(N);
  rep(i,N-1){
    ll t=0;
    for(int j=i;j<N-1;++j){
      if(t<=S[j]) t=S[j]+C[j];
      else{
        t=((t-S[j]+F[j]-1)/F[j])*F[j]+S[j]+C[j];
      }
    }
    cout << t << endl;
  }
  cout << 0 << endl;
}