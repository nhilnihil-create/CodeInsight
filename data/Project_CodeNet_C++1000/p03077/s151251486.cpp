#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,a[5],c;scanf("%lld%lld%lld%lld%lld%lld",&n,&a[0],&a[1],&a[2],&a[3],&a[4]);
  c = min({a[0],a[1],a[2],a[3],a[4]});
  printf("%lld\n",((n%c) ? n/c+1:n/c)+4);
}