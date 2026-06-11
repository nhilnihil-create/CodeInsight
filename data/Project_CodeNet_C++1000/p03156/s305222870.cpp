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
  int n,a,b;
  cin>>n>>a>>b;
  int cnt[3]={0};
  rep(i,n){
    int p;
    cin>>p;
    if(p<=a) cnt[0]++;
    if(p>a && p<=b) cnt[1]++;
    if(p>b) cnt[2]++;
  }
  int ans=500000;
  rep(i,3) ans=min(ans,cnt[i]);
  cout<<ans<<endl;
  

  return 0;
}

