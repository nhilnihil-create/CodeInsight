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
	string s; cin >> s;
	string ns;
	ll N = (ll)s.size();

	for (ll i = 0; i < N;)
	{
		if (i + 1 < N && s[i] == 'B' &&  s[i+1] == 'C')
		{
			ns.push_back('D');
			i += 2;
		}
		else
		{
			ns.push_back(s[i]);
			++i;
		}
	}

	/* std::cout << ns << std::endl; */
	N = (ll)ns.size();

	ll res{0};
	for (ll i = 0; i < N;)
	{
		ll k = i + 1;
		if (ns[i] == 'A')
		{
			while (k < N && (ns[k] == 'A' || ns[k] == 'D')) {++k;}

			string tmp = ns.substr(i, k-i);
			/* std::cout << "i : " << i << std::endl; */
			/* std::cout << "k : " << k << std::endl; */
			/* std::cout << "tmp : " << tmp << std::endl; */
			while (tmp.empty() && tmp.back() == 'A') {tmp.pop_back();}
			reverse(tmp.begin(), tmp.end());
			ll l{0};

			ll M = (ll)tmp.size();
			REP(m, M)
			{
				if (tmp[m] == 'A')
				{
					res += m - l;
					++l;
				}
			}
		}
		i = k;
	}

	std::cout << res << std::endl;
}