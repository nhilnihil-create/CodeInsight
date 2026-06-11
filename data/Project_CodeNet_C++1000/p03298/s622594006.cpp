#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 998244353;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned long long ULL;
//typedef boost::multiprecision::cpp_int bigint;

typedef unsigned long long HASH;

class RollingHash {
public:
	static const ULL HMOD = (1ULL << 61) - 1;
	static const ULL MASK30 = (1ULL << 30) - 1;
	static const ULL MASK31 = (1ULL << 31) - 1;
	static ULL base;
	static const ULL POS = HMOD * ((1ULL << 3) - 1);
	static vector<ULL> powmemo;
	vector<HASH> hash;   //部分列[0,n)のハッシュを持つ
	RollingHash(vector<LL>& S) {
		if (base == 0) {
			random_device rnd;
			mt19937 mt(rnd());
			uniform_int_distribution<ULL> rand(129, HMOD - 1);
			RollingHash::base = rand(mt);
			powmemo.resize(500000, 1);
			for (LL n = 1; n < 500000; n++) {
				powmemo[n] = mod(Mul(powmemo[n - 1], base));
			}
		}
		hash.resize(S.size() + 1);
		hash[0] = 0;
		for (LL n = 1; n <= S.size(); n++) {
			hash[n] = mod(Mul(hash[n - 1], base) + S[n - 1]);
		}
	}
	//部分列[a,b)のハッシュ
	HASH get(LL a, LL b) {
		return mod(hash[b] + POS - Mul(hash[a], powmemo[b - a]));
	}
	//部分列配列への保存なしに変換
	HASH conv(vector<LL>& S) {
		HASH ans = 0;
		for (LL n = 0; n < S.size(); n++) {
			ans = mod(Mul(ans, base) + S[n]);
		}
		return ans;
	}
	static HASH Mul(HASH a, HASH b) {
		HASH au = a >> 31;
		HASH ad = a & MASK31;
		HASH bu = b >> 31;
		HASH bd = b & MASK31;
		HASH midd = au * bd + ad * bu;
		HASH midu = midd >> 30;
		midd = midd & MASK30;
		return ((au * bu) << 1) + ad * bd + (midd << 31) + midu;
	}
	static HASH mod(HASH val) {
		val = (val & HMOD) + (val >> 61);
		if (val >= HMOD)val -= HMOD;
		return val;
	}
};
ULL RollingHash::base = 0;
vector<ULL> RollingHash::powmemo = vector<ULL>();

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	LL N;
	cin >> N;
	VLL front(N), back(N);
	{
		string S;
		cin >> S;
		for (LL n = 0; n < N; n++) {
			front[n] = S[n] - 'a' + 1;
		}
		for (LL n = 0; n < N; n++) {
			back[n] = S[2*N-1-n] - 'a' + 1;
		}
	}
	typedef pair<HASH, HASH> HASHP;
	VLL base(1, 1);
	RollingHash baserh(base);
	map<HASHP, LL> backmap;
	for (LL code = 0; code < ((LL)1 << N); code++) {
		VLL red, blue;
		for (LL n = 0; n < N; n++) {
			if (((LL)1 << n) & code) {
				red.push_back(back[n]);
			}else{
				blue.push_back(back[n]);
			}
		}
		HASH rh = baserh.conv(red);
		HASH bh = baserh.conv(blue);
		auto itr = backmap.find(HASHP(rh, bh));
		if (itr == backmap.end()) {
			backmap.insert(pair<HASHP, LL>(HASHP(rh, bh), 1));
		}
		else {
			itr->second++;
		}
	}
	LL ans = 0;
	for (LL code = 0; code < ((LL)1 << N); code++) {
		VLL red, blue;
		for (LL n = 0; n < N; n++) {
			if (((LL)1 << n) & code) {
				red.push_back(front[n]);
			}
			else {
				blue.push_back(front[n]);
			}
			HASH rh = baserh.conv(red);
			HASH bh = baserh.conv(blue);
			auto itr = backmap.find(HASHP(bh, rh));
			if (itr != backmap.end()) {
				ans += itr->second;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
