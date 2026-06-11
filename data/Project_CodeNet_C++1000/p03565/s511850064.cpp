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
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string S, T; cin >> S >> T;
	ll NS = S.size();
	ll NT = T.size();

	vector<string> res;

	REP(si, NS)
	{
		if (NS - si < NT) continue;
		string tmp;
		REP(i, si)
		{
			if (S[i] == '?')
				tmp.push_back('a');
			else
				tmp.push_back(S[i]);
		}

		bool ok{true};
		REP(i, NT)
		{
			ll ss = i + si;
			ll tt = i;

			if (S[ss] == '?')
			{
				tmp.push_back(T[tt]);
			}
			else 
			{
				if (S[ss] == T[tt])
					tmp.push_back(S[ss]);
				else
					ok = false;
			}
		}
		if (!ok) continue;

		for (ll i = si + NT; i < NS; ++i)
		{
			if (S[i] == '?')
				tmp.push_back('a');
			else
				tmp.push_back(S[i]);
		}
			

		res.push_back(tmp);
	}

	if (res.size() == 0)
	{
		std::cout << "UNRESTORABLE" << std::endl;
		return 0;
	}
	sort(ALL(res));
	std::cout << res[0] << std::endl;
	
	return 0;
}
