#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww {cww() {CIN_ONLY{ios::sync_with_stdio(false); cin.tie(0);}}
}star;
#define DEBUG if(0)
#endif

#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r){bool a = l>r; if (a)l = r; return a;}
template <typename T>inline bool chmax(T &l, T r){bool a = l<r; if (a)l = r; return a;}
template <typename T>istream& operator>>(istream &is, vector<T> &v){for (auto &it : v)is >> it;return is;}

class range {private: struct I { int x; int operator*() { return x; }bool operator!=(I& lhs) { return x<lhs.x; }void operator++() { ++x; } }; I i, n;public:range(int n) :i({ 0 }), n({ n }) {}range(int i, int n) :i({ i }), n({ n }) {}I& begin() { return i; }I& end() { return n; }};

namespace BIT_ {
	using RET = int;
	constexpr int BUF = 2123456;
	int ptr = 0;
	RET t[BUF];
	inline RET* get(const int size) {
		return t;
	}
}
//[1,n],0は扱えない!
struct BIT {
	using T = BIT_::RET;
	T* bit;
	int sz;
	BIT(int n) :bit(BIT_::get(n + 10)), sz(n) {
		fill(bit, bit + n + 10, 0);
	}
	T sum(int i) {
		T s = 0;
		while (i>0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	T sum(int lb, int ub) {
		return sum(ub) - sum(lb - 1);
	}
	void add(int i, T x) {
		while (i <= sz) {
			bit[i] += x; i += i & -i;
		}
	}
};

int N;
LL a[112345];
int b[112345];
int c[112345];
bool f(LL x) {
	LL ok = 0, ng = 0;
	c[0] = N + 10;
	for (int i : range(N)) {
		if (a[i] >= x)b[i] = 1;
		else b[i] = -1;
		c[i + 1] = b[i] + c[i];
	}
	BIT bit(3 * N + 100);
	bit.add(c[0], 1);
	for (int i : range(N)) {
		LL o = bit.sum(c[i + 1]);
		LL n = i + 1 - o;
		ok += o;
		ng += n;
		bit.add(c[i + 1], 1);
	}
	//cout << x << " " << ok << " " << ng << endl;
	return ok >= ng;
}
int main() {
	cin >> N;
	for (int i : range(N)) {
		cin >> a[i];
	}
	LL ub = 1e10;
	LL lb = 0;
	while (ub - lb > 1) {
		const int mid = (lb + ub) / 2;
		(f(mid)? lb : ub) = mid;
	}
	cout << lb << endl;

	return 0;
}
