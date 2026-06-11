#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void cmpmax(T* reference, T value) {
	*reference = max(*reference, value);
}

template<typename T>
void cmpmin(T* reference, T value) {
	*reference = min(*reference, value);
}

const ll mod = 1000000007;

static const ll INF = 1e15;
int n;
vector<ll> as;
vector<P> hs;

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
	SegmentTree<ll> t(n, [=](ll left, ll right) {return max(left, right); }, [=](ll _, ll value) {return value; });
	return t;
}


int main() {
	cin >> n;
	as.resize(n);
	hs.resize(n);
	rep(i, n) {
		int h;
		cin >> h;
		hs[i] = { h, i };
	}
	rep(i, n) {
		cin >> as[i];
	}
	sort(hs.begin(), hs.end());
	auto tree = SegmentTreeMax(n);
	rep(i, n) {
		auto h = hs[i];
		auto index = h.second;
		auto a = as[index];
		auto m = tree.query(0, index - 1);
		tree.update(index, m + a);
	}
	auto upper = tree.query(0, n - 1);
	cout << upper << endl;
	return 0;
}
	
