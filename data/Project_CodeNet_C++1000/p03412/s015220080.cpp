#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

ll mypow(ll b, ll e) {
  if(e==0)
    return 1;
  if(e%2==0) {
    ll t = mypow(b,e/2);
    return t*t;
  }
  return mypow(b,e-1)*b;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  int n;
  cin>>n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  ll ans=0;
  rep(k,30) {
    ll c = 0;
    vector<ll> modb(n);
    ll T = mypow(2,k);
    rep(i,n) modb[i]=b[i]%(2*T);
    sort(modb.begin(),modb.end());
    rep(i,n) {
      ll ta = a[i]%(2*T);
      ll c1 = (lower_bound(modb.begin(),modb.end(),(2*T-ta))-lower_bound(modb.begin(),modb.end(),T-ta));
      ll c2 = (lower_bound(modb.begin(),modb.end(),(4*T-ta))-lower_bound(modb.begin(),modb.end(),3*T-ta));
      c+=(c1+c2);
    }
    if(c%2==1) {
      ans+=mypow(2,k);
    }
  }
  cout << ans << endl;
  return 0;
}
