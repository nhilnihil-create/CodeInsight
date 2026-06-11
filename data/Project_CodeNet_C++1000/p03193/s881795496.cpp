//スマホから提出
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1010],b[1010];
int main(void)
{
  ll n,h,w;
  cin >>n>>h>>w;
  ll ans=0;
  for(ll i=0;i<n;i++) {
    cin >> a[i] >> b[i];
    if(a[i]>=h&&b[i]>=w) ans++;
  }
  cout << ans<<endl;
}