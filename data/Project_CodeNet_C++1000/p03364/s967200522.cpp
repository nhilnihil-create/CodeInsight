#include <bits/stdc++.h>

using ll = long long;
#define int long long

// [a -> b-1]
#define reps(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
// [0 -> a-1]
#define rep(i, a) reps(i, 0, (a))
// [a-1 -> b]
#define rreps(i, a, b) for (int i = (int)((a)-1); i >= (int)(b); i--)
// [a-1 -> 0]
#define rrep(i, a) rreps(i, a, 0)
#define all(v) (v).begin(), (v).end()
// next_permutation(all(v))
#define PERM(v) next_permutation(all(v))
/*sort(all(v));
 * (v).erase(unique(all(v)), v.end())*/
#define UNIQUE(v)\
	sort(all(v));\
	(v).erase(unique(all(v)), v.end())
#define MINV(v) min_element(all(v))
#define MAXV(v) max_element(all(v))
#define MIN3(a, b, c) min(min(a, b), c)
#define MIN4(a, b, c, d) min(MIN3(a, b, c), d)
#define MIN5(a, b, c, d, e) min(MIN4(a, b, c, d), e)
#define MIN6(a, b, c, d, e, f) min(MIN5(a, b, c, d, e), f)
#define MAX3(a, b, c) max(max(a, b), c)
#define MAX4(a, b, c, d) max(MAX3(a, b, c), d)
#define MAX5(a, b, c, d, e) max(MAX4(a, b, c, d), e)
#define MAX6(a, b, c, d, e, f) max(MAX5(a, b, c, d, e), f)
// b is [a, c)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
// c is [a, e) && d is [b, f)
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmin3(a, b, c) a = MIN3(a, (b), (c))
#define chmin4(a, b, c, d) a = MIN4(a, (b), (c), (d))
#define chmin5(a, b, c, d, e) a = MIN5(a, (b), (c), (d), (e))
#define chmin6(a, b, c, d, e, f) a = MIN6(a, (b), (c), (d), (e), (f))
#define chmax(a, b) a = max(a, (b))
#define chmax3(a, b, c) a = MAX3(a, (b), (c))
#define chmax4(a, b, c, d) a = MAX4(a, (b), (c), (d))
#define chmax5(a, b, c, d, e) a = MAX5(a, (b), (c), (d), (e))
#define chmax6(a, b, c, d, e, f) a = MAX6(a, (b), (c), (d), (e), (f))
#define fcout cout << fixed << setprecision(15)
#define YES(f) cout << ((f) ? YES_STR : NO_STR) << endl;

using namespace std;



namespace rolling_hash {
struct Random_CompileTime {
	using result_type = uint_fast64_t;
	result_type x;
	static constexpr result_type min() {return 0u;}
	static constexpr result_type max() {return UINT64_MAX;}
	constexpr Random_CompileTime(result_type a) : x(a) {}
	constexpr Random_CompileTime(const char* s) : x(hash(s)) {}
	constexpr result_type hash(const char* s) {
		result_type res = 12892336203476015549u;
		result_type mul = 8106227557068529044u;
		for (int i = 0; s[i] != '\0'; i++) {
			res += result_type(s[i]) * mul;
			mul = mul * max() + 12664609216090335131u;
		}
		return res;
	}
	constexpr uint_fast32_t get_base() {
		x = x ^ (x << 13); x = x ^ (x >> 7);
		return uint_fast32_t(((x ^ (x << 17)) & ((1 << 27) - 1)) + 218810u);
	}
};
template<uint_fast32_t max_len, uint_fast32_t base = Random_CompileTime(__TIME__).get_base(), uint_fast64_t mod = (1UL << 61) - 1, uint_fast64_t MASK30 = (1UL << 30) - 1, uint_fast64_t MASK31 = (1UL << 31) - 1>
struct RollingHash {
	using hash_type = uint_fast64_t;
	// uint_fast32_t base;
	int sz;
	vector<hash_type> hash;
	static array<hash_type, max_len+1> power;
	RollingHash(const string& s) : sz(s.length()), hash(sz + 1, 0) {
		for (int i = 0; i < sz; i++) {
			hash[i+1] = calc_mod(mul(hash[i], base) + s[i]);
		}
	}
	inline hash_type mul(hash_type a, hash_type b) {
		hash_type au = a >> 31;
		hash_type ad = a & MASK31;
		hash_type bu = b >> 31;
		hash_type bd = b & MASK31;
		hash_type mid = ad * bu + au * bd;
		return ((au * bu) << 1) + ad * bd + ((mid & MASK30) << 31) + (mid >> 30);
	}
	inline hash_type calc_mod(hash_type a) {
		a = (a & mod) + (a >> 61);
		if (a >= mod) a -= mod;
		return a;
	}
	inline hash_type get(int l, int r) {
		return calc_mod(hash[r] + mod * 7 - mul(hash[l], power[r-l]));
	}
	inline hash_type connect(hash_type h1, hash_type h2, int h2_len) {
		return calc_mod(mul(h1, power[h2_len]) + h2);
	}
	inline hash_type connect(int l1, int r1, int l2, int r2) {
		return connect(get(l1, r1), get(l2, r2), r2 - l2);
	}
};
template<uint_fast32_t max_len, uint_fast32_t base, uint_fast64_t mod, uint_fast64_t MASK30, uint_fast64_t MASK31>
struct PowCalc {
	using hash_type = typename RollingHash<max_len, base, mod, MASK30, MASK31>::hash_type;
	array<hash_type, max_len+1> power;
	constexpr hash_type mul(hash_type a, hash_type b) {
		hash_type au = a >> 31;
		hash_type ad = a & MASK31;
		hash_type bu = b >> 31;
		hash_type bd = b & MASK31;
		hash_type mid = ad * bu + au * bd;
		return ((au * bu) << 1) + ad * bd + ((mid & MASK30) << 31) + (mid >> 30);
	}
	constexpr hash_type calc_mod(hash_type a) {
		a = (a & mod) + (a >> 61);
		if (a >= mod) a -= mod;
		return a;
	}
	constexpr PowCalc() {
		power[0] = 1;
		for (uint_fast32_t i = 0; i < max_len; i++) {
			power[i+1] = calc_mod(mul(power[i], base));
		}
	}
};
template<uint_fast32_t a, uint_fast32_t b, uint_fast64_t c, uint_fast64_t d, uint_fast64_t e>
array<typename RollingHash<a, b, c, d, e>::hash_type, a+1> RollingHash<a, b, c, d, e>::power = PowCalc<a, b, c, d, e>().power;
} 
using namespace rolling_hash;

#define cin input
#define cout output

void solve(istream& input, ostream& output) {
	int N; cin >> N;
	vector<string> R(N);
	vector<string> C(N);
	vector<RollingHash<300>> RR;
	vector<RollingHash<300>> RC;
	rep(i, N) {
		cin >> R[i];
		RR.emplace_back(R[i]);
	}
	rep(i, N) {
		rep(j, N) {
			C[i] += R[j][i];
		}
		RC.emplace_back(C[i]);
	}
	int res = 0;
	rep(i, N) {
		rep(j, N) {
			bool f = true;
			int r = i, c = j;
			rep(k, N) {
				f &= RR[r].connect(j, N, 0, j) == RC[c].connect(i, N, 0, i);
				if (++r == N) r -= N;
				if (++c == N) c -= N;
			}
			res += f;
		}
	}
	cout << res << endl;
}

#undef cin
#undef cout

#ifndef CHECK_CPP

signed main() {
	solve(cin, cout);
}

#endif
