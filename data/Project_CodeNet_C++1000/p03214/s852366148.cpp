#include<bits/stdc++.h>
#define ll long long
#define INF 10000000000000ll
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i>=0;i++)
using namespace std;
signed main(){
  double n,a[1000],sum[1000],mp=INF,cun=0,b=0;
  cin>>n;
  rep(i,n){
    cin>>a[i];
    cun+=a[i];
  }
  cun = cun / n;
  rep(i,n){
    sum[i] = abs(a[i]-cun);
    if(mp>sum[i]){
      mp = sum[i];
      b = i;
    }
  }
  cout<<b<<"\n";
}