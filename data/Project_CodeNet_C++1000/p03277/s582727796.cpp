#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
#define base 100010
namespace bit{
  ll dat[2*base];
  void init(){
      for(int i=0;i<2*base;i++)dat[i]=0;
  }
  void add(ll i){
      i+=base;
      for(;i<2*base;i+=i&-i){
          dat[i]++;
      }
  }
  ll qry(ll i){
      i+=base;
      ll res=0;
      for(;i;i-=i&-i){
          res+=dat[i];
      }
      return res;
  }
};
ll n,a[100010];
bool solve(ll key){
    ll rui=0;
    bit::init();
    bit::add(0);
    ll res=0;
    for(int i=0;i<n;i++){
        if(a[i]>=key)rui++;
        else rui--;
        res+=bit::qry(rui);
      bit::add(rui);
    }
    return res*2>=n*(n+1)/2;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  ll l=-1,r=1e10,mid;
  while(l<r-1){
      mid=(l+r)>>1;
      if(solve(mid))l=mid;
      else r=mid;
  }
  cout<<l<<endl;
  return 0;
}

