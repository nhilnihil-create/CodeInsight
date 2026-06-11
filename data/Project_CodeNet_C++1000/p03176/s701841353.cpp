#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmax(T& ref, const T value) {
	if (ref < value) ref = value;
}

const ll mod = 1000000007;

constexpr ll m = 1e9 + 7;

class modint {
	using u64 = std::int_fast64_t;

public:
	u64 a;
	modint(const u64 x = 0) noexcept : a(x% m) {}
	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	modint& operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= m) {
			a -= m;
		}
		return *this;
	}
	modint& operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += m;
		}
		a -= rhs.a;
		return *this;
	}
	modint& operator*=(const modint rhs) noexcept {
		a = a * rhs.a % m;
		return *this;
	}
};

ostream& operator<<(ostream& stream, const modint& data) {
	stream << data.a;
	return stream;
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
	SegmentTree<ll> t(n, [=](ll left, ll right) {return max(left, right); }, [=](ll _, ll value) {return value; });
	return t;
}


int main() {
	ll n;
	cin >> n;
	vector<ll> hs(n);
	vector<ll> vs(n);
	rep(i, n) {
		cin >> hs[i];
	}
	rep(i, n) {
		cin >> vs[i];
	}
	auto dp = SegmentTreeMax(n + 2);
	dp.update(hs[0], vs[0]);
	for (int i = 1; i < n; i++) {
		auto add = vs[i];
		ll upper = dp.query(0, hs[i]);
		dp.update(hs[i], upper + add);
	}
	ll u = dp.query(0, n + 1);
	cout << u << endl;
    return 0;
}
