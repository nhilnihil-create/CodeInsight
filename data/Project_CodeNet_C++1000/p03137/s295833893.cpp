#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,m,s = 0,i;scanf("%lld%lld",&m,&n);
  if(m>=n){
    printf("0\n");return 0;
  }
  ll x[n],d[n-1];
  for(i=0;i<n;i++) scanf("%lld",&x[i]);
  sort(x,x+n);
  for(i=0;i<n-1;i++) d[i] = x[i+1]-x[i];
  sort(d,d+n-1,greater<ll>());
  for(i=0;i<m-1;i++) s += d[i];
  printf("%lld\n",x[n-1]-x[0]-s);
}