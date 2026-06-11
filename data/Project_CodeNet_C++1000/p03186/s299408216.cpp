#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll a,b,c; cin>>a>>b>>c;
  ll ans=0;
  
  if (a+b+1>=c) ans=b+c;
  else ans=a+2*b+1;

  cout<<ans<<endl;
}

