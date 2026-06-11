#define NOMINMAX
#define TEST_MODE true

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep2(i, a, b) for (int i = (a)-1; i >= (int)b; --i)
#define range(i, a, b, c) for (int i = a;             \
                                   c > 0 ? i < b : i > b; \
                                   i += c)
#define chmax(a, b) (a = (a) < (b) ? (b) : (a))
#define chmin(a, b) (a = (a) > (b) ? (b) : (a))
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) begin(a), end(a)
#define ifnot(a) if (not(a))
#define int long long

#ifdef LOCAL_ENV

#if TEST_MODE == true
const bool test = true;
#define dump(x) cerr << #x << " = " << (x) << " "
#define dumpl(x) dump(x) << endl
#else
const bool test = false;
#define dump(x) 
#define dumpl(x)
#endif

#else
const bool test = false;
#define dump(x) 
#define dumpl(x)
#endif

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
const int INF = (int)1 << 60;
const ll INFL = (ll)1 << 60;
ll mod_n = (int)1e9 + 7;
const double eps = 1e-10;
typedef long double Real;
// return -1, 0, 1
int sgn(const Real &r) { return (r > eps) - (r < -eps); }
int sgn(const Real &a, const Real &b) { return sgn(a - b); }

//.....................
const int MAX = (int)2e5 + 5;

vector<string> split(const string &str, char sep)
{
	vector<string> v;
	stringstream ss(str);
	string buffer;
	while (getline(ss, buffer, sep))
	{
		v.push_back(buffer);
	}
	return v;
}

string join(const vector<string>& v, const char* delim = 0) {
	string s;
	if (!v.empty()) {
		s += v[0];
		for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i) {
			if (delim) s += delim;
			s += v[i];
		}
	}
	return s;
}

template <class InputIterator>
int sum(InputIterator begin, InputIterator end)
{
	return accumulate(begin, end, 0ll);
}

template<typename T>
T gcd(T a, T b)
{
	T c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

template<typename T>
T bit_count(T N) {
	T cnt = 0;
	while (N) {
		if (N & 1) cnt++;
		N >>= 1;
	}
	return cnt;
}

template<typename T>
void print_vec(ostream& ostream, vector<T> a) {
	rep(i, a.size() - 1) ostream << a[i] << " ";
	ostream << a.back() << endl;
}

template<class T>
T pow_n(T x, T n) {
	T res = 1;
	while (n > 0) {
		if (n & 1) res = res * x;
		x = x * x;
		n >>= 1;
	}
	return res;
}

struct Point {
	int y, x;
};

class Solver {
public:
	int H, W;

	bool grid_ok(int y, int x) {
		return 0 <= y && y < H && 0 <= x && x < W;
	}

	int N;
	vector<int> max_v2;
	vector<int> t2, v2;

	void set_max_v2() {
		max_v2.resize(N * 405);
		rep(i, max_v2.size()) max_v2[i] = INF;
		int cur_t = t2[0];
		rep2(i, 1, N) {
			rep(t2, 205) {
				int cur_t2 = cur_t - t2;
				if (cur_t2 < 0) break;
				chmin(max_v2[cur_t2], v2[i] + t2);
			}
			cur_t += t2[i];
		}
	}

	double ans() {
		int cur_t2 = 0;
		int cur_v2 = 0;
		double res = 0;
		int a[] = { 1, 0, -1 };
		rep(i, N) {	
			dumpl(v2[i]);
			rep(loop, t2[i]) {
				int next_v2 = -1;
				rep(j, 3) {
					int hoping_v2 = cur_v2 + a[j];
					if (hoping_v2 <= max_v2[cur_t2 + 1]
						&&hoping_v2 <= v2[i]) {
						chmax(next_v2, hoping_v2);
					}
				}
				res += (double)(cur_v2 + next_v2) / 8;
				cerr << next_v2 << " ";

				cur_t2 += 1;
				cur_v2 = next_v2;
			}
		}
		cerr << endl;
		return res;
	}

	void solve() {
		vector<int> t, v;
		cin >> N;
		t.resize(N + 1); rep(i, N) cin >> t[i];
		v.resize(N + 1); rep(i, N) cin >> v[i];
		N += 1;
		t[N - 1] = 1;
		v[N - 1] = 0;

		t2.resize(N); rep(i, N) t2[i] = t[i] * 2;
		v2.resize(N); rep(i, N) v2[i] = v[i] * 2;

		set_max_v2();

		for (auto& v : max_v2) cerr << v << " ";
		cerr << endl;

		cout << ans() << endl;
	}

};

signed main()
{
	srand((unsigned int)time(NULL));
	cout << fixed << setprecision(20);
	auto ptr = new Solver();
	ptr->solve();
	delete ptr;
	//while (true) {
	//	if (cin.eof() == true) break;
	//	auto ptr = new Solver();
	//	ptr->solve();
	//	delete ptr;
	//}
	return 0;
}
