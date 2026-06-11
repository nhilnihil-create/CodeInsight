#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,K; cin>>N>>K;
  vector<pair<ll,ll>>Z(N);
  vector<ll>X(N),Y(N);
  for(int i=0; i<N; i++){
    ll x,y; cin>>x>>y;
    X[i]=x, Y[i]=y, Z[i]={x,y};
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  ll ans=4e18+1;
  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      for(int a=0; a<N-1; a++){
        for(int b=a+1; b<N; b++){
          ll wl=X[i], wh=X[j], hl=Y[a], hh=Y[b], temp=0;
          for(int k=0; k<N; k++){
            if(wl<=Z[k].first && Z[k].first<=wh && hl<=Z[k].second && Z[k].second<=hh) temp++;
          }
          if(temp>=K) ans=min(ans,(wh-wl)*(hh-hl));
        }
      }
    }
  }
  cout<<ans<<endl;
}