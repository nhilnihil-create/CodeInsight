#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,dis=0; cin>>n;
  vector<ll> a(n+2),d(n+1);
  a[0] = 0; a[n+1] = 0;
  for(int i=1; i<=n+1; i++) {
    cin>>a[i];
    d[i] = abs(a[i]-a[i-1]);
    dis += d[i];
  }
  for(int i=1; i<=n; i++) {
    cout<<dis+abs(a[i-1]-a[i+1])-(abs(a[i-1]-a[i])+abs(a[i]-a[i+1]))<<endl;
  }
}