#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<double,ll,ll>T;
#define PI 3.14159265358979
const int MOD = 1e9 + 7;

int main(){
  ll A,B,Q;
  cin>>A>>B>>Q;
  vector<ll>a(A+2);
  vector<ll>b(B+2);
  vector<ll>q(Q);
  a[0]=-100000000000ll;
  b[0]=-100000000000ll;
  a[A+1]=100000000000ll;
  b[B+1]=100000000000ll;
  rep(i,A){cin>>a[i+1];}
  rep(i,B){cin>>b[i+1];}
  rep(i,Q){cin>>q[i];}
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  rep(i,Q){
  	auto t=*upper_bound(a.begin(), a.end(), q[i]);
    auto k=upper_bound(a.begin(), a.end(), q[i]);
    k--;
    ll T=*k;
    auto s=*upper_bound(b.begin(),b.end(), q[i]);
    auto u=upper_bound(b.begin(),b.end(), q[i]);
    u--;
    ll S=*u;
    ll x=abs(t-q[i]),w=abs(T-q[i]),z=abs(s-q[i]),y=abs(S-q[i]);
    ll ans=min(min(max(w,y),max(x,z)),min(w+z+min(w,z),x+y+min(x,y)));  
    cout<<ans<<endl;
  }
}
