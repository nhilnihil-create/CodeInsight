#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) < (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pll Dir[8] = { //移動
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};

//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL

struct Edge {
	int from, to;
	ll w;
};
typedef vector<vector<Edge>> Graph;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll calc(ll m) {
	ll ret = 0;
	while (m)
	{
		ret += m % 10LL;
		m /= 10LL;
	}
	return ret;
}

template<class Int> struct Fraction {//{{{
	Int num, den;

private:
	static Int gcd(Int a, Int b) {
		while (b) swap(a %= b, b);
		return a;
	}
	void normalize() {
		Int g = gcd(num, den);
		num /= g; den /= g;
		if (den < 0) { num = -num; den = -den; }
	}
public:
	Fraction() { num = 0, den = 0; }
	Fraction(Int num) : num(num), den(1) { }
	Fraction(Int num, Int den, bool need_normalize = true) : num(num), den(den) {
		if (need_normalize) normalize();
	}

	Fraction operator-() const {
		return Fraction(-num, den, false);
	}
};//}}}
using Z = ll;
using Q = Fraction<Z>;
ll sgn(const Z a) {
	return (a > 0) - (a < 0);
}
ll sgn(const Z a, const Z b) {
	return (a > b) - (a < b); // sgn(a-b) にするとオーバーフローしやすい.
}
ll sgn(const Q &a) {
	return sgn(a.num);
}
ll sgn(Q a, Q b) {
/*
	if ((long double )a.num / a.den >= (long double)b.num / b.den) return 1;
	else -1;
*/
	if (a.num <= 0 || b.num <= 0) {
		if (a.num == 0 || b.num == 0) return sgn(a.num, b.num);
		if ((a.num < 0) ^ (b.num < 0)) return sgn(a.num, b.num);
		return sgn(-b, -a);
	}
	if (ll s = sgn(a.num / a.den, b.num / b.den)) return s;
	a.num %= a.den;
	b.num %= b.den;
	// 0 な方の .den が 1 だから, オーバーフローしない.
	if (a.num == 0 || b.num == 0) return sgn(a.num * b.den, a.den * b.num);
	return sgn(Q(b.den, b.num, false), Q(a.den, a.num, false));
}
Q upp[13 * 999];
signed main(void) {
	int k;
	cin >> k;


	ll base[13], base2[13];
	base[12] = 0, base2[12] = 1;
	for (int i = 11; 0 <= i; i--) {
		base[i] = base[i + 1] * 10 + 9;
		base2[i] = base2[i + 1] * 10;
	}

	int cou = 0;
	REP(i, 13){
		
		for (int j = 999; 0 <= j; j--) {

			if (i != 0 && j % 10 == 9) continue;

			ll m = base2[i] * j + base[i];
			upp[cou].num = m;
			upp[cou].den = calc(m);
			cou++;
		}

	}
	
	sort(begin(upp), end(upp), [](const Q &a, const Q &b) {
		return a.num > b.num;
	});
	cou--;

	Q Min = upp[0];
	vector<int> ans;

	REP(i, cou){
		if (sgn(Min, upp[i]) >= 0) {
			ans.push_back(i);
			Min = upp[i];
		}
	}
	sort(ALL(ans), greater<int>());
	REP(i, k)
		printf("%lld\n", upp[ans[i]].num);
	return 0;
}

