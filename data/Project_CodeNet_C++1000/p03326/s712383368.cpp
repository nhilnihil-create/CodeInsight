#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<ll,ll,ll>
#define pr(x) cout << x << endl;
using namespace std;
 
int main(){
  int n,m; cin >> n >> m;
  vector<T> cakes;
  rep(i,n){
    ll x,y,z; cin >> x >> y >> z;
    cakes.emplace_back(x,y,z);  
  }

  ll ans=0;

  rep(i,2)rep(j,2)rep(k,2){
    vector<ll> sum(n);
    rep(p,n){
      ll nx,ny,nz;
      tie(nx,ny,nz) = cakes[p];
      if(i==1) nx*=-1;
      if(j==1) ny*=-1;
      if(k==1) nz*=-1;
      sum[p]=nx+ny+nz;
    }
    sort(all(sum));
    ll tmp=0;
    rep(i,m) tmp+=sum[n-i-1];
    ans=max(ans,tmp);
  }
  cout << ans << endl;
return 0;
}