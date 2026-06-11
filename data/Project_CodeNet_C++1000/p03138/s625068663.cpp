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

constexpr ll MAX_D = 50;
ll dp[100][2];

int main(int argc, char **argv)
{
	ll N, K; cin >> N >> K;
	vector<ll> A(N); REP(i, N) cin >> A[i];
	memset(dp, -1, sizeof dp);
	**dp = 0;

	for (ll bits = 0; bits < MAX_D; ++bits)
	{
		ll mask = 1ll << (MAX_D - bits - 1);

		ll cnt1{0}, cnt0{0};
		
		REP(i, N)
		{
			if (A[i] & mask) ++cnt1;
			else ++cnt0;
		}

		ll cost0 = mask * cnt1;
		ll cost1 = mask * cnt0;

		if (dp[bits][true] != -1)
		{
			chmax(dp[bits+1][true], dp[bits][true] + cost0);
			chmax(dp[bits+1][true], dp[bits][true] + cost1);
		}

		if (dp[bits][false] != -1)
			if (K & mask)
				chmax(dp[bits+1][true], dp[bits][false] + cost0);

		if (dp[bits][false] != -1)
		{
			if (K & mask)
				chmax(dp[bits+1][false], dp[bits][false] + cost1);
			else
				chmax(dp[bits+1][false], dp[bits][false] + cost0);
		}
	}

	std::cout << max(dp[MAX_D][0], dp[MAX_D][1]) << std::endl;
}
