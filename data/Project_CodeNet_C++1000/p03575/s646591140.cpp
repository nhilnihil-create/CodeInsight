#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(x) cout<<x<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18;

class UnionFind{
private:
	vector<ll> Parent;
public:
	UnionFind(ll N){
		Parent = vector<ll>(N, -1);
	}

	ll root(ll A){
		if(Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	ll size(ll A){
		return -Parent[root(A)];
	}

	bool connect(ll A, ll B){
		A = root(A);
		B = root(B);
		if(A == B){
			return false;
		}
		if(size(A) < size(B)) swap(A, B);
		Parent[A] += Parent[B];
		Parent[B] = A;
		return true;
	}

	bool isSame(ll A, ll B){
		return root(A) == root(B);
	}
};

ll n,m;


signed main()
{
	cin.tie( 0 ); ios::sync_with_stdio( false );
	cin>>n>>m;
	vpll ab(m);
	rep(i,m){
		ll a,b; cin>>a>>b; a--,b--;
		ab[i]={a,b};
	}
	ll ans=0;
	rep(i,m){
		UnionFind uf(n);
		rep(j,m){
			if(i==j) continue;
			uf.connect(ab[j].first,ab[j].second);
		}
		bool ok=true;
		rep(i,n){
			if(!uf.isSame(0LL,i)) ok=false;
		}
		if(!ok) ans++;
	}
	cout<<ans<<endl;
}