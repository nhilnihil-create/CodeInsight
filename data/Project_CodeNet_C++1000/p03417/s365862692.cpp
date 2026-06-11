#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  ll n,m,ans;cin>>n>>m;
  if(n*m==1)ans=1;
  else if(n==1||m==1)ans=n*m-2;
  else ans=n*m-2*(n+m)+4;
  cout<<ans<<endl;
}