#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n;
  cin >> n;
  ll x[n],y[n],h[n];
  for(ll i=0;i<n;i++)cin >> x[i] >> y[i] >> h[i];

  ll m,X,Y;
  for(ll i=0;i<=100;i++){
    for(ll j=0;j<=100;j++){
      ll ans;
      bool ok=true;
      for(ll k=0;k<n;k++){
        if(h[k]!=0){
          ans=abs(x[k]-i)+abs(y[k]-j)+h[k];
          break;
        }
      }
      for(ll k=0;k<n;k++){
        if(h[k]==0){
          if(ans-abs(x[k]-i)-abs(y[k]-j)>0){
            ok=false;
            break;
          }
        }
        else{
          if(ans!=abs(x[k]-i)+abs(y[k]-j)+h[k]){
            ok=false;
            break;
          }
        }
      }
      if(ok){
        X=i;
        Y=j;
        m=ans;
      }
    }
  }

  cout << X << " " << Y << " " <<  m << endl;

}