#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

template<class T>
bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return false;
	}
	return true;
}

template<class T>
bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return false;
	}
	return true;
}

template<class T>
bool chmax(T &a, initializer_list<T> l)
{
	return chmax(a, *max_element(l.begin(), l.end()));
}

template<class T>
bool chmin(T &a, initializer_list<T> l)
{
	return chmin(a, *min_element(l.begin(), l.end));
}


ll MAX_B = 50;
ll dp[100][2];

int main(int argc, char **argv)
{
	ll N, K; cin >> N >> K;
	vector<ll> A(N);
	REP(i, N) cin >> A[i];

	REP(i, 100) dp[i][0] = dp[i][1] = -1;
	**dp = 0;

	REP(b, MAX_B)
	{
		ll mask = 1ll << (MAX_B - b - 1);

		ll cnt1{0};
		REP(i, N)
		{
			if (mask & A[i]) ++cnt1;
		}

		ll add0 = cnt1 * mask;
		ll add1 = (N - cnt1) * mask;

		if (dp[b][true] != -1)
			chmax(dp[b+1][true], dp[b][true]+max(add0, add1));

		if (dp[b][false] != -1)
			if (mask & K)
				chmax(dp[b+1][true], dp[b][false]+add0);

		if (dp[b][false] != -1)
		{
			if (mask & K)
				chmax(dp[b+1][false], dp[b][false] + add1);
			else
				chmax(dp[b+1][false], dp[b][false] + add0);
		}
	}

	std::cout << max(dp[MAX_B][true], dp[MAX_B][false] )<< std::endl;
}
