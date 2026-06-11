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
  sort(ALL(c));
  long long ans=0;
  rep(i,n){
    ans+=(lower_bound(ALL(a),b[i])-a.begin())
      *(c.end()-upper_bound(ALL(c),b[i]));
  }
  cout<<ans<<endl;  
}
