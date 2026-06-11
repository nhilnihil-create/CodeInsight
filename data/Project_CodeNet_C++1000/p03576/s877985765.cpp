#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,k;
  cin>>n>>k;
  P a[n];
  ll b[n];
  ll c[n];
  rep(i,0,n){
    ll x,y;
    cin>>x>>y;
    a[i]=P(x,y);
    b[i]=x;
    c[i]=y;
  }
  sort(b,b+n);
  sort(c,c+n);
  ll ans=4e19;
  rep(i,0,n-1){
    rep(j,i+1,n){
      rep(h,0,n-1){
        rep(l,h+1,n){
          int cnt=0;
          rep(m,0,n){
            if(b[i]<=a[m].first && a[m].first<=b[j] && c[h]<=a[m].second && a[m].second<=c[l]){
              cnt++;
            }
          }
          if(cnt>=k){
            ans=min(ans,(b[j]-b[i])*(c[l]-c[h]));
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}