
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e18;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

template<typename T> class SegmentTree {
private:
	typedef function<T(T, T)> F;
	int n;
	T d0;
	vector<T> vertex;
	F f;
	F g;
public:

	SegmentTree(int sourceN, F f, F g, T d = 0) :d0(d), f(f), g(g) {
		init(sourceN);
	}
	void init(int sourceN) {
		n = 1;
		while (n < sourceN) n *= 2;
		vertex.resize(2 * n - 1, d0);
	}
	void update(int i, T x) {
		int k = i + n - 1;
		vertex[k] = g(vertex[k], x);
		while (k > 0) {
			k = (k - 1) / 2;
			vertex[k] = f(vertex[2 * k + 1], vertex[2 * k + 2]);
		}
		return;
	}
	T query(int l, int r) {
		T vl = d0, vr = d0;
		l += n - 1;
		r += n - 1;
		for (; l <= r; l /= 2, r = r / 2 - 1) {
			if (l % 2 == 0) vl = f(vl, vertex[l]);
			if (r & 1) vr = f(vr, vertex[r]);
		}
		return f(vl, vr);
	}
};


static SegmentTree<ll> SegmentTreeMax(int n) {
	SegmentTree<ll> t(n, [=](ll left, ll right) {return max(left, right); },
		[=](ll _, ll value) {return value; });
	return t;
}

static SegmentTree<ll> SegmentTreeRangeMinimumQuery(int n) {
	SegmentTree<ll> t(n, [=](ll left, ll right) {return min(left, right); },
		[=](ll _, ll value) {return value; },
		1e18);
	return t;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> cs(n,0), ss(n,0), fs(n,1);
	rep(i, n-1) {
		cin >> cs[i] >> ss[i] >> fs[i];
	}
	vector<ll> ans;
	rep(i, n) {
		ll t = 0;
		for (int j = i; j < n-1; j++) {
			chmax(t, ss[j]);
			if (t % fs[j]) {
				t = (t / fs[j] + 1) * fs[j];
			}
			t += cs[j];
		}
		ans.push_back(t);
	}
	rep(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}
