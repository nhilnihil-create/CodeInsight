#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const int M=100010;

int main(){
  int n;
  cin>>n;
  
  map<ll,ll> m;
  m[0]=1;
  
  ll a,sum=0;
  rep(i,n){
    cin>>a;
    sum+=a;
    m[sum]++;
  }
  
  ll b,ans=0;
  for(auto u:m){
    b=u.second;
    ans=ans+b*(b-1)/2;
  }
  
  cout<<ans<<endl;
  
  return 0;
}