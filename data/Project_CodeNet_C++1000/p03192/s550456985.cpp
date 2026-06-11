#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  string s;
  int ans=0;
  cin>>s;
  rep(i,s.size() ){
    if(s[i]=='2') ans++;
  }
  cout<<ans<<endl;

  return 0;
}
