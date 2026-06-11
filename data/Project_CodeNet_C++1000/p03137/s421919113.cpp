#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n,m;
  cin>>n>>m;
  vector<ll> x(m);
  for(int i=0;i<m;i++) cin>>x[i];
  sort(x.begin(),x.end());
  vector<ll> d;
  for(int i=0;i<m-1;i++) d.push_back(x[i+1]-x[i]);
  sort(d.begin(),d.end());
  ll ans=0;
  for(int i=0;i<m-n;i++) ans+=d[i];
  cout << ans << endl;
}