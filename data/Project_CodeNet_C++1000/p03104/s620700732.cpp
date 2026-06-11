#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

ll func(ll n){
  ll ans = 0;
  rep(i,40) {
    ll freq = 1LL<<(i+1);
    if(i==0) {
      ll num = (n+1)/freq;
      if(num%2==1) ans += 1;
      continue;
    }
    if((n+1)%freq>(freq/2) && ((n+1)%freq)%2==1) {
      ans += 1LL<<i;
    }
  }
  return ans;
}


int main () {
  ll a,b;cin>>a>>b;
  ll reta = func(a-1),retb = func(b);
  //  cout<<reta<<" "<<retb<<endl;
  ll ans = reta^retb;
  cout<<ans<<endl;
}
