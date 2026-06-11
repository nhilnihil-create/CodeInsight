//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 922337203685477580LL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

template<class T>
struct SegTree {
	using FX = function<T(T, T)>;
	int n;
	FX fx;
	const T ex;
	vector<T> dat;
	SegTree(int n_, FX fx_, T ex_):fx(fx_), ex(ex_), n(1) {
		while(n < n_) n <<= 1;
		dat.assign((n<<1)-1, ex);
	}
	inline int chld(int k) {return (k<<1)+1;}
	inline int chrd(int k) {return (k<<1)+2;}
	void update(int i, T x) {
		i += n-1;
		dat[i] = x;
		while(i) {
			i = (i-1)>>1;
			dat[i] = fx(dat[chld(i)], dat[chrd(i)]);
		}
	}
	inline T query(int a, int b) {return query(a, b, 0, 0, n);}
	T query(int a, int b, int k, int l, int r) {
		if(r <= a || b <= l) return ex;
		if(a <= l && r <= b) return dat[k];
		T vl = query(a, b, chld(k), l, (l+r)>>1);
		T vr = query(a, b, chrd(k), (l+r)>>1, r);
		return fx(vl, vr);
	}
	const T &operator[](int idx) const {return dat[idx+n-1];}
};

const int N = 2e5+10;

//head

int n;
int h[N], a[N];
SegTree<ll> seg(N, [](ll a, ll b)->ll{return max(a, b);}, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	rep(i, n) cin >> h[i];
	rep(i, n) cin >> a[i];
	rep(i, n) {
		h[i]--;
		seg.update(h[i], seg.query(0, h[i])+a[i]);
	}
	cout << seg.query(0, n) << endl;
}