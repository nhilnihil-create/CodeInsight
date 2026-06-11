#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i;
  ll a[200005];
  
  cin >> n;
  for (i=1;i<=n;i++) cin >> a[i];
  
  a[0]=0;
  for (i=1;i<=n;i++) a[i]+=a[i-1];
  
  ll ans=1e18;
  for (i=2;i<n-1;i++){
    ll *p1,*p2;
    ll s;
    p1=lower_bound(a+1,a+i+1,a[i]/2+1);
    p2=lower_bound(a+i+1,a+n+1,(a[n]+a[i])/2+1);
    for (int j=0;j<2;j++){
      for (int k=0;k<2;k++){
        s=max({*p1,a[i]-*p1,*p2-a[i],a[n]-*p2})-min({*p1,a[i]-*p1,*p2-a[i],a[n]-*p2});
        ans=min(ans,s);
        p1--;
      }
      p1+=2;
      p2--;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}