#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[2005]={0};
int main(){
  ll n,z,w;
  cin>>n>>z>>w;
  for(int i=1;i<=n;i++) cin>>ar[i];
  if(n==1) cout<<abs(ar[1]-w)<<endl;
  else cout<<max(abs(ar[n]-w),abs(ar[n-1]-ar[n]))<<endl;
}
