#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<ll> xv,yv;
int main(){
  ll n,k;
  cin>>n>>k;
  vector<P> vec;
  for(int i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    vec.push_back(P(x,y));
    xv.push_back(x);
    yv.push_back(y);
  }
  sort(xv.begin(),xv.end());
  sort(yv.begin(),yv.end());
  ll ans=((ll)1<<62);
  for(int a=0;a<n;a++){
    for(int b=a;b<n;b++){
      for(int c=0;c<n;c++){
        for(int d=c;d<n;d++){
          ll lx=xv[a],rx=xv[b],ly=yv[c],ry=yv[d];
          ll cnt=0;
          for(int i=0;i<n;i++){
            ll x=vec[i].first,y=vec[i].second;
            if(lx<=x&&x<=rx&&ly<=y&&y<=ry) cnt++;
          }
          if(cnt>=k){
            ans=min(ans,(rx-lx)*(ry-ly));
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}
