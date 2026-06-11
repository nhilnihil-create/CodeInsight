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
};

ostream& operator<<(ostream& stream, const modint& data) {
	stream << data.a;
	return stream;
}

int main() {
	ll n;
	cin >> n;
	vector<vector<bool>> match(n, vector<bool>(n, false));
	rep(i, n) {
		rep(j, n) {
			int ok;
			cin >> ok;
			match[i][j] = ok;
		}
	}
	vector<vector<modint>> dp(n+1, vector<modint>(1LL << n, 0));
	dp[0][0] = 1;
	//dp[i][j]...i番目までみてj状態になる組み合わせの数
	rep(i, n) {
		rep(j, 1LL << n) {
			auto p = __builtin_popcountll(j);
			if (p != i) continue;
			rep(a, n) {
				if (!match[i][a]) continue;
				if (j & (1LL << a)) continue;
				dp[i + 1][j | (1LL << a)] += dp[i][j];
			}
		}
	}
	cout << dp[n][(1LL << n) - 1LL] << endl;

    return 0;
}
