#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  ll l=0,r=n;
  while(l+1<r) {
    ll m=(l+r)>>1;
    map<ll,ll> cnt;
    cnt[a[0]]=0;
    ll f=1;
    ll zl=0,zr=0;
    for(ll i=1;i<n;i++) {
      if(a[i]>a[i-1]) {
        cnt[a[i]]=0;
        zr=a[i];
        if(a[i-1]) {
          zl=a[i-1]+1;
        }
      }
      else {
        if(m==1) {
          f=0;
          break;
        }
        ll id=a[i];
        while(id) {
          if(zl<=id&&id<=zr) {
            cnt[id]=1;
            zr=id-1;
            break;
          }
          cnt[id]++;
          if(cnt[id]>=m) {
            cnt[id]=0;
            id--;
          }
          else break;
        }
        if(id==0) f=0;
      }
      if(!f) break;
    }
    if(f) r=m;
    else l=m;
  }
  cout << r << endl;
}