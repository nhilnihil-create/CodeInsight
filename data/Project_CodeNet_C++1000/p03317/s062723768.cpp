#include<bits/stdc++.h>
using namespace std;
#define itn int
#define int long long
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,k,p,sum=0;
  itn a[1000000];
  cin>>n>>k;
  n-=k;
  if(n==0) cout<<1<<"\n";
  else cout<<n/(k-1)+(n%(k-1)!=0?1:0)+1<<"\n";
}