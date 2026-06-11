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

int main(){
  ll n,a,b;
  ll mi=1e17;
  ll sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>a>>b;
      sum+=a;
      if(a>b)chmin(mi,b);
  }
  if(mi==1e17)cout<<0<<endl;
  else cout<<sum-mi<<endl;
  return 0;
}
