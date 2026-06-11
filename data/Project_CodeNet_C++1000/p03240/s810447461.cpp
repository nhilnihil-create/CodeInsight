#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N;cin>>N;
  vector<ll> x(N),y(N),h(N);rep(i,N) cin>>x[i]>>y[i]>>h[i];
  //中心i,j
  rep(i,101){
    rep(j,101){
      ll H;
      rep(k, N){
        if(h[k]!=0){
        H = abs(i-x[k])+abs(j-y[k])+h[k];
        break;
        }
      }
      bool flag=true;
      rep(k, N){
        if(h[k]==0 && abs(i-x[k])+abs(j-y[k])<H){
          flag=false;
          break;
        }
        else if(h[k]>0 && abs(i-x[k])+abs(j-y[k])+h[k]!=H){
          flag=false;
          break;
        }
      }
      if(flag) cout << i << " " <<  j << " " << H << endl;
    }
  }
}