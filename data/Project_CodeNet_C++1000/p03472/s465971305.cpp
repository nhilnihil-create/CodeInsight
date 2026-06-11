#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)

int main() {
  ll n,h; cin >> n >> h;
  vector<pair<ll, ll>> p(n);

  for(ll i=0;i<n;i++){
  cin >> p[i].first >> p[i].second;
    }

  sort(p.begin(), p.end());

  vector<ll> bx(n-1);
  rep(i,n-1)bx[i]=p[i].second;
  sort(bx.begin(),bx.end(),greater<ll>());

  ll amax=p[n-1].first; ll cnt=0; ll b=p[n-1].second;
  if(b>=h){
    cout << 1 << endl;
    return 0;
  }

  rep(i,n-1){
    if(bx[i]>=amax){
    h-=bx[i];
    cnt++;
     if(h<=0){
      cout << cnt << endl;
      return 0;
     }
     else if(h>0 && h<=b){
       cout << cnt+1 << endl;
       return 0;
     }
     }
    }



    while(h>b){
      h-=amax;
      cnt++;
    }
    if(h>0 && h<=b)cout << cnt+1 << endl;
    else cout << cnt << endl;

}