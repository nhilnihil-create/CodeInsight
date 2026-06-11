#include <iostream>
#include <algorithm>
using namespace std; typedef long long ll; const int INF=1e9;
typedef pair<int,int> P;

int main() {
  int n; cin>>n;
  int m=1<<n;
  int a[m], b[m], c[m], d[m];
  fill(b,b+m,0); for(int i=0;i<m;i++) c[i]=i; fill(d,d+m,-1);
  for(int i=0;i<m;i++) cin>>a[i];

  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
      if (i & (1<<j)) continue;
      int id=i|(1<<j);
      P us[4]={{a[i],c[i]}, {b[i],d[i]}, {a[id],c[id]}, {b[id],d[id]}};
      sort(us,us+4);
      a[id]=us[3].first; c[id]=us[3].second;
      if (us[3].second != us[2].second) b[id]=us[2].first, d[id]=us[2].second;
      else b[id]=us[1].first, d[id]=us[1].second;
      //if (a[i] > a[id]) b[id]=a[id], a[id]=a[i];
      //else if (a[i] > b[id]) b[id]=a[i];
    }
  }
  //for(int i=0;i<m;i++) cout<<a[i]<<" "; cout<<endl;
  //for(int i=0;i<m;i++) cout<<b[i]<<" "; cout<<endl;

  ll an=0;
  for(int i=1;i<m;i++) {
    an=max(an, (ll)(a[i]+b[i]));
    cout<<an<<endl;
  }
}