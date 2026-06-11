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

ll a[200020];

int main() {
  int n;cin>>n;
  rep(i,n) cin>>a[i];
  ll p=a[0],q=0,r=a[1]+a[2],s=0;
  ll ans = 1LL<<60;
  int c1=0,c2=2;
  rep(i,n-3) s+=a[i+3];
  for(int i = 1;i<n-2;i++){
    q+=a[i];
    r-=a[i];
    while(c1+1<i&&abs(q-p)>abs(p+2*a[c1+1]-q)){
      c1++;
      p+=a[c1];
      q-=a[c1];
    }
    while(c2+1<n-1&&abs(r-s)>abs(r+2*a[c2+1]-s)) {
      c2++;
      r+=a[c2];
      s-=a[c2];
    }
    ll mn=1000000000000000,mx=-1;
    mn=min(mn,p);
    mn=min(mn,q);
    mn=min(mn,r);
    mn=min(mn,s);
    mx=max(mx,p);
    mx=max(mx,q);
    mx=max(mx,r);
    mx=max(mx,s);
    ans = min(ans,mx-mn);
  }
  cout<<ans<<endl;
}

