#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
ll n,d[101]={},z[100]={};
int main(void){
  cin>>n;
  for(int i=2;i<=n;i++){
    ll a=i,j=2;
    while(a!=1){
      if(a%j!=0){
        j++;
      }
      else{
        a/=j;
        d[j]++;
      }
    }
  }
  for(int i=2;i<=n;i++){
    z[d[i]]++;
  }
  for(int j=n;j>=2;j--){
    z[j]+=z[j+1];
  }
  ll ans=z[4]*(z[4]-1)*(z[2]-2)/2+z[24]*(z[2]-1)+z[14]*(z[4]-1)+z[74];
  cout<<ans<<endl;
}