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

ll n;
vector<vector<int>> g;
vector<vector<modint>> dp;

modint dfs(int current, int parent, bool black) {
	if (dp[current][black].a >= 0) return dp[current][black];
	modint ans = 1;
	for (auto c : g[current]) {
		if (c == parent) continue;
		modint nc = dfs(c, current, false);
		if (!black) {
			nc += dfs(c, current, true);
		}
		ans *= nc;
	}
	dp[current][black] = ans;
	return ans;
}

int main() {
	cin >> n;
	g.resize(n);
	dp.resize(n, vector<modint>(2, -1));
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	modint ans = dfs(0, -1, false);
	ans += dfs(0, -1, true);
	cout << ans << endl;
    return 0;
}
