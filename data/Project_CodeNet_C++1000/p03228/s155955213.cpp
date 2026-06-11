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
  int a,b,k;
  cin>>a>>b>>k;
  rep(i,k){
    if(i%2==0){
      if(a%2==1) a--;
      a/=2;
      b+=a;
    }else{
      if(b%2==1) b--;
      b/=2;
      a+=b;
    }
  }
  cout<<a<<" "<<b<<endl;
      

  return 0;
}
