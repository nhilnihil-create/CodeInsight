#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  ll d=abs(a-b)+abs(b-c);
  ll e=abs(a-c)+abs(b-c);
  ll f=abs(a-c)+abs(a-b);
  cout<<min(d,min(e,f))<<endl;
  return 0;
}
