#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

vector<ll> toDivisor(ll num)
{
	vector<ll> d;
	for (ll i = 1; i*i <= num; ++i)
	{
		if (i*i == num)
		{
			d.push_back(i);
		}
		else if (num % i == 0)
		{
			d.push_back(i);
			d.push_back(num/i);
		}
	}
	return d;
}


vector<pair<ll, ll>> toDivisorP(ll num)
{
	vector<pair<ll, ll>> d;
	for (ll i = 1; i * i <= num; ++i)
	{
		if (i*i == num) d.push_back(pair<ll, ll>(i, i));
		else if (num % i == 0)
		{
			d.push_back(pair<ll, ll>(i, num/i));
		}
	}
	return d;
}

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<pair<ll, ll>> v = toDivisorP(N);

	ll res{0};
	for (auto &p : v)
	{
		// std::cout << "(" << p.first << ", " << p.second << ")"<< std::endl;
		if (p.first < p.second-1)
			res += p.second - 1;
	}
	std::cout << res << std::endl;
}