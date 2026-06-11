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
vector<ll> v[300010];
int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  if(n-a>a*(b-1)||n-a<b-1){
      cout<<-1<<endl;
      return 0;
  }
  ll s=0;
  for(ll p=n-a;p>0;p--){
      if(v[s].size()==b-1)s++;
      v[s].push_back(p);
  }
  for(ll i=a-1;i>=0;i--){
      cout<<n-i<<endl;
      for(auto t:v[i])cout<<t<<endl;
  }
  return 0;
}
