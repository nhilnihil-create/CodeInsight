#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

class modint {
	static constexpr std::int_fast64_t Modulus = 1e9 + 7;
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
	constexpr modint operator*(const ll rhs) const noexcept {
		return modint(*this) *= modint(rhs);
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
	ll x,y,z,k;
	cin >> x >> y >> z >> k;
	vector<ll> as(x), bs(y), cs(z);
	rep(i, x) cin >> as[i];
	rep(i, y) cin >> bs[i];
	rep(i, z) cin >> cs[i];
	vector<ll> xy;
	rep(i, x) {
		rep(j, y) {
			xy.push_back(as[i] + bs[j]);
		}
	}
	sort(xy.begin(), xy.end(), greater<ll>());
	sort(cs.begin(), cs.end(), greater<ll>());
	vector<ll> ans;
	for (int i = 0; i < min<ll>(xy.size(), k); i++) {
		for (int j = 0; j < min<ll>(cs.size(), k); j++) {
			ans.push_back(xy[i] + cs[j]);
		}
	}
	sort(ans.begin(), ans.end(), greater<ll>());
	rep(i, k) {
		cout << ans[i] << endl;
	}

	return 0;
}
