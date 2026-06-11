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
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int a[100];
  double sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  sum/=n;
  double min=BIG;
  int sam=0;
  rep(i,n){
    if(min > abs(a[i]-sum) ){
      min=abs(a[i]-sum);
      sam=i;
    }
  }
  cout<<sam<<endl;

  return 0;
}
