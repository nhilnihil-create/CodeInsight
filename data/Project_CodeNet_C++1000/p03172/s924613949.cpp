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
	ll n, k;
	cin >> n >> k;
	vector<ll> as(n);
	rep(i, n) cin >> as[i];

	vector<vector<modint>> dp(n + 1, vector<modint>(k + 2, 0));
	vector<vector<modint>> sums(n + 1, vector<modint>(k + 2, 0));
	//dp[i][j]...i番目までの人でj-1個をわける組み合わせ
	//dp[i][0]...dp[i-1][0];
	//dp[i][1]...dp[i-1][1] + dp[i-1][0];
	//dp[i][2]...dp[i-1][2] + dp[i-1][1] + dp[i-1][0];
	//dp[i][j]...dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-as[i]];
	for (int i = 0; i <= as[0]; i++) {
		dp[0][i+1] = 1;
	}
	rep(i, k+1) {
		sums[0][i + 1] = sums[0][i] + dp[0][i + 1];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j + 1] = sums[i - 1][j + 1] - sums[i - 1][max(0LL, j + 1 - as[i] - 1)];
		}
		rep(j, k + 1) {
			sums[i][j + 1] = sums[i][j] + dp[i][j + 1];
		}
	}
	cout << dp[n - 1][k+1] << endl;
    return 0;
}
