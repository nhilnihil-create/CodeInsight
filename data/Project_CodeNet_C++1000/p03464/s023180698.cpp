#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll k,i,l,r;scanf("%lld",&k);
  ll d[k];pair<ll,ll> a[k+1] = {};
  a[0] = make_pair(2,2);
  for(i=k-1;i>=0;i--) scanf("%lld",&d[i]);
  for(i=0;i<k;i++){
    l = a[i].first/d[i]+(a[i].first%d[i] != 0);
    r = a[i].second/d[i];
    if(a[i].second<l*d[i]){
      printf("-1\n");return 0;
    }
    a[i+1].first = l*d[i];
    a[i+1].second = (r+1)*d[i]-1;
  }
  //for(i=0;i<=k;i++) printf("%lld %lld\n",a[i].first,a[i].second);
  printf("%lld %lld\n",a[k].first,a[k].second);
}