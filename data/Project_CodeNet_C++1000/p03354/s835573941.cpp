#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using ch = char;
using db = double;
using bl = bool;
using vll = vector<long long>;
using vdb = vector<db>;
using vvll = vector<vll>;
using vst = vector<st>;
using vch = vector<char>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
#define rep(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b;return true;} return false;}
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b;return true;} return false;}
const ll mod = 1000000007;
const ll inf = 1LL << 60;
const db pi = acos(-1.0L);

struct unionfind{
	vll par;
	unionfind(ll n) : par(n) {
		rep(i, 0, n) par.at(i) = i;
	}
	ll root(ll x){
		if(par.at(x) == x) return x;
		return par.at(x) = root(par.at(x));
	}
	void unite(ll x, ll y){
		ll rx = root(x), ry = root(y);
		par.at(rx) = ry;
	}
	bl same(ll x, ll y){
		ll rx = root(x), ry = root(y);
		return rx == ry;
	}
};

int main(){
	ll n, m;
	cin >> n >> m;
	vll p(n);
	vin(p);
	unionfind tree(n);
	rep(i, 0, m){
		ll x, y;
		cin >> x >> y;
		x--; y--;
		tree.unite(x, y);
	}
	ll ans = 0;
	rep(i, 0, n) if(tree.same(i, p.at(i) - 1)) ans++;
	cout << ans << endl;
}