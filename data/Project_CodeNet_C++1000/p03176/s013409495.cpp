#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;
const int MAX_N = 131702;

ll pow(ll a, ll n) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a) {
		if (n % 2LL == 1LL) {
			ret = ret * a;
		}
	}
	return ret;
}

struct SegmentTree{//RMQ

  ll n;
  ll dat[MAX_N*4];

  void init(){
    for(ll i = 0LL; i < 2LL*n-1LL;i++) dat[i]=0LL;
  }

  void update(ll i,ll x) {
    i += n-1LL;
    dat[i]=x;

    while(i>0LL){
      i=(i-1LL)/2LL;
      dat[i]=max(dat[i*2LL+1LL],dat[i*2LL+2LL]);
    }
  }

  ll query(ll a,ll b,ll k, ll l, ll r){
    if(r<=a||b<=l) return 0LL;
    if(a<=l&&r<=b) return dat[k];
    else{
      ll vl = query(a,b,k*2LL+1LL,l,(l+r)/2LL);
      ll vr = query(a,b,k*2LL+2LL,(l+r)/2LL,r);
      return max(vl,vr);
    }
  }
};

int main() {
  ll N;
  cin>>N;
  vector<ll> h(N);
  vector<ll> a(N);
  for(ll i = 0LL; i < N; i++) {cin>>h[i];h[i]--;}
  for(ll i = 0LL; i < N; i++) cin>>a[i];
  ll cnt = 0LL;
  ll s = N-1;
  while(s>0){
    s/=2LL;
    cnt++;
  }
  ll n = pow(2,cnt);
  SegmentTree tree={n};
  tree.init();
  for(ll i = 0LL; i < N; i++){
    tree.update(h[i],tree.query(0,h[i],0,0,n)+a[i]);
  }
  cout<<tree.dat[0]<<endl;
}