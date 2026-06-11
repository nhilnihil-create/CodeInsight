#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n,z,w;
  cin>>n>>z>>w;
  int a[n];
  int mx=0;
  rep(i,n){
    cin>>a[i];
    mx=max(mx,a[i]);
  }
  if(n==1){
    cout<<abs(a[0]-w)<<endl;
  }else{
    cout<<max(abs(a[n-1]-w),abs(a[n-2]-a[n-1]));
  }


  return 0;
}
