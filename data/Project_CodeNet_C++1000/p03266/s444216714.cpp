#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin>>a;
  ll b;
  cin>>b;
  ll c=a/b;
  ll d=c*c*c;
  if(b%2==0){
    ll e=a/(b/2)-c;
    d+=e*e*e;
  }
  cout<<d<<endl;
  return 0;
}