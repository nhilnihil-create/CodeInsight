#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N; cin >> N;
	string s; cin >> s;
	
	map<char, ll>m;
	for (auto &e : s)
	{
		++m[e];
	}

	ll res{1};
	for (auto &p : m)
	{
		(res *= (p.second + 1)) %= MOD;
	}

	std::cout << (res +  MOD- 1) % MOD << std::endl;
}