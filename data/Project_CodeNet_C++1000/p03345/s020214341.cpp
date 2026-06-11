#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std; typedef long long ll; const ll INF=1e16; typedef pair<int,int> P;

int main() {
  ll a,b,c,k; cin>>a>>b>>c>>k;
  // b+c a+c a+b
  // 2a+b+c a+2b+c a+b+2c
  // p0+a p0+b p0+c
  // p1+p0+a p1+p0+b p1+p0+c
  if (k%2) cout<<b-a<<endl;
  else cout<<a-b<<endl;
}