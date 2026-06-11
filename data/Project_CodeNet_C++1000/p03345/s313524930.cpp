#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  ll a,b,c,k;
  cin>>a>>b>>c>>k;
  if(k%2==0) cout<<a-b<<endl;
  else cout<<b-a<<endl;
  return 0;
}
