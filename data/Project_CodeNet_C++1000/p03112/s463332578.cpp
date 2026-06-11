//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const ll inf=1ll<<60;

int main(){
  int a,b,q;
  cin >> a >> b >> q;
  vector<ll> s(a+4); s[0]=-inf-1; s[1]=-inf; s[a+2]=inf; s[a+3]=inf+1;
  vector<ll> t(b+4); t[0]=-inf-1; t[1]=-inf; t[b+2]=inf; t[b+3]=inf+1;
  for(int i=2;i<=a+1;i++) cin >> s[i];
  for(int i=2;i<=b+1;i++) cin >> t[i];
  vector<ll> x(q);
  rep(i,q) cin >> x[i];
  rep(i,q){
    ll a1=*lower_bound(all(s),x[i]);
    ll b1=*prev(lower_bound(all(s),x[i]),1);
    ll c1=*lower_bound(all(t),a1);
    ll d1=*prev(lower_bound(all(t),a1),1);
    ll e1=*lower_bound(all(t),b1);
    ll f1=*prev(lower_bound(all(t),b1),1);
    ll dist1=inf;
    chmin(dist1,abs(x[i]-a1)+abs(a1-c1));
    chmin(dist1,abs(x[i]-a1)+abs(a1-d1));
    chmin(dist1,abs(x[i]-b1)+abs(b1-e1));
    chmin(dist1,abs(x[i]-b1)+abs(b1-f1));
    ll a2=*lower_bound(all(t),x[i]);
    ll b2=*prev(lower_bound(all(t),x[i]),1);
    ll c2=*lower_bound(all(s),a2);
    ll d2=*prev(lower_bound(all(s),a2),1);
    ll e2=*lower_bound(all(s),b2);
    ll f2=*prev(lower_bound(all(s),b2),1);
    ll dist2=inf;
    chmin(dist2,abs(x[i]-a2)+abs(a2-c2));
    chmin(dist2,abs(x[i]-a2)+abs(a2-d2));
    chmin(dist2,abs(x[i]-b2)+abs(b2-e2));
    chmin(dist2,abs(x[i]-b2)+abs(b2-f2));
    ll ans=min(dist1,dist2);
    cout << ans << endl;
  }
}