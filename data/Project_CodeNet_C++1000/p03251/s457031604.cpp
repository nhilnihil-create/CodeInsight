#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m,x,y;cin>>n>>m>>x>>y;
  vector<int>a(n),b(m);
  rep(i,n)cin>>a[i];
  rep(i,m)cin>>b[i];
  sort(all(a));
  sort(all(b));
  if(a[n-1]<b[0]&&x<b[0]&&a[n-1]<y)cout<<"No War"<<endl;
  else cout<<"War"<<endl;
}