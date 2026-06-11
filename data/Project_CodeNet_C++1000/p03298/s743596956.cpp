#include <bits/stdc++.h>
#include <string>
#define ull unsigned long long
#define ll long long
#define pp pair<ull, ull>

using namespace std;

const ull base = 233;

int N;
map<pp, int> cntR;
string str;

inline int bitswap(int x)
{
	int ret = 0;
	for (int i = 0; i < N; i++)
		ret = ret * 2 + (x >> i & 1);
	return ret;
}

pp gethash(int S, int dir)
{
	string s = dir ? str.substr(N) : str.substr(0, N);
	pp ret = pp(0, 0);
	for (int i = 0; i < N; i++)
		if (S >> i & 1)
			ret.first = ret.first * base + s[i];
	reverse(s.begin(), s.end());
	S = (1 << N) - bitswap(S) - 1;
	string tmp;
	for (int i = 0; i < N; i++)
		if (S >> i & 1)
		{
			ret.second = ret.second * base + s[i];
			tmp += s[i];
		}
//	cerr << S << ' ' << dir << ' ' << tmp << endl;
	return ret;
}

int main()
{
	cin >> N >> str;
	for (int S = 0; S < (1 << N); S++)
		cntR[gethash(S, 1)]++;
	ll ans = 0;
	for (int S = 0; S < (1 << N); S++)
	{
		pp cur = gethash(S, 0);
		ans += cntR[pp(cur.second, cur.first)];
	}
	cout << ans << endl;
	return 0;
}
