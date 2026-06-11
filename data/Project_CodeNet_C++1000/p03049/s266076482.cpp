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
	vector<string> S(N);
	REP(i, N) cin >> S[i];

	ll res{0};
	ll s_a{0}, s_b{0}, s_ab{0};
	
	REP(i, N)
	{
		ll M= S[i].size();
		string &s = S[i];
		
		if (s.front() == 'B' && s.back() != 'A') ++s_b;
		else if (s.back() == 'A' && s.front() != 'B') ++s_a;
		else if (s.back() == 'A' && s.front() == 'B') ++s_ab;
		for (ll k = 0; k < M-1;)
		{
			if (s[k] == 'A' && s[k+1] == 'B')
			{
				++res;
				k+=2;
			}
			else
				++k;
		}
	}

	if (s_ab == 0)
		std::cout << res + min(s_a, s_b) << std::endl;
	else if (s_a + s_b > 0)
		std::cout << res + min(s_a, s_b) + s_ab << std::endl;
	else
		std::cout << res + s_ab - 1 << std::endl;
}
