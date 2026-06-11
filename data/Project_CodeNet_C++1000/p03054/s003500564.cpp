#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll H, W, N;
ll a, b;
string A, B;

bool is(ll h, ll w)
{
	return (0 <= h && h < H) && (0 <= w && w < W);
}

int main(int argc, char **argv)
{
	cin >> H >> W >> N >> a >> b >> A >> B;
	--a, --b;

	bool ok{true};
	ll w{b};

	// right
	REP(i, N)
	{
		if (A[i] == 'R')
			++w;
		if (!is(a, w)) ok = false;

		if (B[i] == 'L' && w != 0)
			--w;
	}

	w = b;
	// left
	REP(i, N)
	{
		if (A[i] == 'L')
			--w;
		if (!is(a, w)) ok = false;
		if (B[i] == 'R' && w != W-1)
			++w;
	}

	ll h{a};
	// top
	REP(i, N)
	{
		if (A[i] == 'U') --h;
		if (!is(h, b)) ok = false;
		if (B[i] == 'D' && h != H-1)
			++h;
	}

	h = a;
	REP(i, N)
	{
		if (A[i] == 'D') ++h;
		if (!is(h, b)) ok = false;
		if (B[i] == 'U' && h != 0)
			--h;
	}

	std::cout << (ok ? "YES" : "NO") << std::endl;
}
