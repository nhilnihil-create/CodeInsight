#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N; cin>>N;
  vector<vector<ll>> A(N,vector<ll>(3,0));
  for(ll i=0; i<N; i++) cin>>A[i][0]>>A[i][1]>>A[i][2];
  sort(A.begin(), A.end(), [](auto& x, auto& y){return x[2] > y[2];});  
  ll H;
  for(ll X=0; X<=100; X++){//頂点の全探索
    for(ll Y=0; Y<=100; Y++){
      H=abs(X-A[0][0])+abs(Y-A[0][1])+A[0][2];
      for(ll i=1; i<N; i++){
        ll x=A[i][0];
        ll y=A[i][1];
        ll h=A[i][2];
        ll dif=H-abs(X-x)-abs(Y-y);
        if(h>0 && dif!=h) break;
        else if(h==0 && dif>0) break;
        if(i==N-1){
          cout<<X<<" "<<Y<<" "<<H<<endl;
          return 0;
        }
      }
    }
  }
}
