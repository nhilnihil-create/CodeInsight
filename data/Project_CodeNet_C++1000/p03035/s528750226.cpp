#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  if(a<6){
    cout<<0<<endl;
  }
  else if(a>12){
    cout<<b<<endl;
  }
  else{
    cout<<b/2<<endl;
  }
  return 0;
}