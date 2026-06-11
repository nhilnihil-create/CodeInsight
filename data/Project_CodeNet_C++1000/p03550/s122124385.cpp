#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,z,w;
  cin>>n>>z>>w;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  ll cnt1=abs(a[n-1]-w),cnt2=0;
  if(n>=2) cnt2=abs(a[n-1]-a[n-2]);
  cout<<max(cnt1,cnt2)<<endl;
}