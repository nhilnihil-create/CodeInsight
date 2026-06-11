#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  ll n;
  cin>>n;
  ll ans=0;
  bool f=false;
  ll last=1e12;
  for(ll i=0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    ans+=b;
    if(a>b){
      last=min(last,b);
    }
    if(a!=b) f=true;
  }
  if(last!=1e12) ans-=last;
  cout<<(f?ans:0)<<endl;
}
