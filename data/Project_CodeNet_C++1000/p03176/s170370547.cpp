#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct segtree{
	int size;
	vector<ll> mx;

	void init(int n){
		size=1;
		while(size<n) size*=2;
		mx.assign(2*size, 0);
	}

	void set(int i, ll v, int x, int lx, int rx){
		if(rx-lx==1){
			mx[x]=v; 
			return;
		}
		int m=(lx+rx)/2;
		if(i<m) set(i, v, 2*x+1, lx, m);
		else set(i, v, 2*x+2, m, rx);
		mx[x]=max(mx[2*x+1], mx[2*x+2]);
	}

	void set(int i, ll val){
		set(i, val, 0, 0, size);
	}

	ll calc(int l, int r, int x, int lx, int rx){
		if(lx>=r || rx<=l) return 0;
		if(lx>=l && rx<=r) return mx[x];
		int m=(lx+rx)/2;
		return max(calc(l, r, 2*x+1, lx, m), calc(l, r, 2*x+2, m, rx));
	}

	ll calc(int l, int r){
		return calc(l, r, 0, 0, size);
	}
};

ll n, x;
vector<ll> h, a;

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n;
  rep(i, 1, n){
  	cin >> x; h.pb(x);
  }
  rep(i, 1, n){
  	cin >> x; a.pb(x);
  }

  segtree st;
  st.init(n+1);

  ll ans=0;
  rep(i, 0, n-1){
  	ll best=st.calc(1, h[i])+a[i];
  	ans=max(ans, best);
  	st.set(h[i], best);
  }
  cout << ans;
}