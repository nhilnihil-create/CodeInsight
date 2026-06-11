#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

class modint {
	static constexpr std::int_fast64_t Modulus = 998244353;
	using u64 = std::int_fast64_t;

public:
	u64 a;
	constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint& operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint& operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint& operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr operator u64() const { return a; }
};

int main() {
	ll n;
	cin >> n;
	map<ll, ll> ms;
	rep(i, n) {
		ll d;
		cin >> d;
		ms[d]++;
	}
	ll m;
	cin >> m;
	vector<ll> ps(m);
	for (int i = 0; i < m; i++) {
		cin >> ps[i];
	}
	for (auto p : ps) {
		if (ms[p] <= 0) {
			cout << "NO" << endl;
			return 0;
		}
		ms[p]--;
	}
	cout << "YES" << endl;
	return 0;
}
