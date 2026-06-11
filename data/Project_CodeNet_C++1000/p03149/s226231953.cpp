#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int a[4];
  int b[4]={1,4,7,9};
  rep(i,4) cin>>a[i];
  sort(a,a+4);
  rep(i,4){
    if(a[i]!=b[i]){cout<<"NO"<<endl;return 0;}
  }
  cout<<"YES"<<endl;

  return 0;
}