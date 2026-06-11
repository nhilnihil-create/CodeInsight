#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dpa[100005],dpb[100005],dpc[100005];

int main()
{
  ll n;
  cin>>n;
  ll a[n],b[n],c[n];
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i]>>c[i];
  }
  dpa[n-1]=a[n-1];
  dpb[n-1]=b[n-1];
  dpc[n-1]=c[n-1];
  for(int i=n-2;i>=0;i-- ){
   dpa[i]=a[i]+max(dpb[i+1],dpc[i+1]);
   dpb[i]=b[i]+max(dpa[i+1],dpc[i+1]);
   dpc[i]=c[i]+max(dpb[i+1],dpa[i+1]);
  }
  cout<<max(dpa[0],max(dpb[0],dpc[0]));
    return 0;
}
