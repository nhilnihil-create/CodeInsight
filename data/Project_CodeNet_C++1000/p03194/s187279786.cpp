#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  ll n,p;
  cin>>n>>p;

  if(n==1){
    cout<<p<<endl;
    return 0;
  }

  map<ll,ll> mp;
  ll i=2;
  while(i*i<=p){
    if(p%i==0){
      mp[i]++;
      p/=i;
    }else{
      i++;
    }
  }
  mp[p]++;
  ll ans=1;
  for(ll j=2;j<=i;j++) ans*=pow(j,mp[j]/n);

  cout<<ans<<endl;
  
  return 0;
}