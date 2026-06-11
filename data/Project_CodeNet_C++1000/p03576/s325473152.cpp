#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,K;cin >> n >> K;
  vector<ll> x(n),y(n);
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
  }
  ll ans=5e18;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
          ll u=x[i],v=x[j],w=y[k],z=y[l];
          int cnt=0;
          for(int m=0;m<n;m++){
            if(min(u,v)<=x[m]&&x[m]<=max(u,v)&&min(w,z)<=y[m]&&y[m]<=max(w,z)){
              cnt++;
            }
          }
          if(cnt>=K){
            ans=min(ans,abs(v-u)*abs(z-w));
          }
        }
      }
    }
  }
  cout << ans << endl;
}