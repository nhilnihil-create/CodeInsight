#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main() {
  ll n; cin >> n;
  ll asum=0,bsum=0;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i]; asum+=a[i];
  }
  rep(i,n){
    cin >> b[i]; bsum+=b[i];
  }
  if(asum<bsum){
    cout << -1 << endl;
    return 0;
  }
  vector<ll> dif(n);
  ll fsum=0, cnt=0;
  rep(i,n){
    dif[i]=a[i]-b[i];
     if(dif[i]<0){
       fsum+=dif[i]*(-1); cnt++;
     }
  }
  if(fsum==0){
    cout << 0 << endl;
    return 0;
  }

  sort(dif.begin(),dif.end());
   ll psum=0;
   for(ll i=n-1;n>=0;i--){
    psum+=dif[i];cnt++;
    if(psum>=fsum){
      break;
    }
  }
  cout << cnt << endl;

}
