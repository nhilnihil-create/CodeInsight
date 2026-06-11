#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000000000000000;
const long double PI=3.14159265358979;
const ll MAX=100010;

int main() {
  ll N,M;
  string s,t;
  cin>>N>>M>>s>>t;
  ll g=__gcd(N,M);
  ll ans=N*M/__gcd(N,M);
  N/=g;
  M/=g;
  ll c=1;
  for(int i=0;i<g;i++){
  //  cout<<N*i<<" "<<M*i<<endl;
    if(s[i*N]!=t[i*M]){
      c=0;
      break;
    }
  }
  if(c){
    cout<<ans;
  }
  else{
    cout<<-1;
  }
  
}
