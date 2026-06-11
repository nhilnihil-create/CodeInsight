#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int n,k;
  cin >> n >> k;
  vector<ll> x(n),y(n);
  vector<ll> xx(n),yy(n);
  for(int i=0;i<n;++i){
    cin >> x[i] >> y[i];
    xx[i]=x[i];
    yy[i]=y[i];
  }

  sort(xx.begin(),xx.end());
  sort(yy.begin(),yy.end());

  //for(int i=0;i<n;++i) cout << xx[i] << endl;

  ll cal=(xx[n-1]-xx[0])*(yy[n-1]-yy[0]);
  //cout << xx[0] << endl;
  //cout << cal << endl;
  for(int xl=0;xl<n;++xl){
    for(int xr=xl+1;xr<n;++xr){
      for(int yd=0;yd<n;++yd){
        for(int yu=yd+1;yu<n;++yu){
          int cnt=0;
          for(int i=0;i<n;++i){
            if(xx[xl]<=x[i] && xx[xr]>=x[i] && yy[yd]<=y[i] && yy[yu]>=y[i])cnt++;
          }
          if(cnt>=k){
            ll tmp=abs(xx[xl]-xx[xr])*abs(yy[yu]-yy[yd]);
            cal=min(cal,tmp);
          }
        }
      }
    }
  }
  cout << cal << endl;
  return 0;
}
