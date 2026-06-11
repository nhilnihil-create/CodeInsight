#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ALL(x) x.begin(),x.end()

int main(){
  int n;
  cin>>n;
  vector<int> a(n),b(n),c(n);
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];
  rep(i,n) cin>>c[i];
  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));
  vector<vector<int>::iterator> via(n),vic(n);
  rep(i,n) via[i]=lower_bound(ALL(a),b[i]);
  rep(i,n) vic[i]=upper_bound(ALL(c),b[i]);

  long long da,dc,ans=0;
  rep(i,n){
    da=distance(a.begin(),via[i]);
    dc=distance(vic[i],c.end());
    ans+=da*dc;
  }
  cout<<ans<<endl;  
}