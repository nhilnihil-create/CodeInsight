#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll F[510][510];
ll H, W;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};


int main(int argc, char **argv)
{
	cin >> H >> W;
	REP(h, H)REP(w, W)
		cin >> F[h][w];


	ll h{0}, w{0};
	ll dh{1}, dw{1};
	bool is_to{false};
	vector<vector<ll>> rv;
	
	while (true)
	{
		if (F[h][w]&1)
		{
			is_to ^= true;
		}

		ll nh = h + dh;
		ll nw;
		
		if (nh < 0 || nh >= H)
		{
			dh *= -1;
			nw = w + dw;
			nh = h;

			if (nw >= W) break;
		}
		else
		{
			nw = w;
		}

		if (is_to)
		{
			vector<ll> tmp{h, w, nh, nw};
			rv.push_back(tmp);
		}

		h = nh;
		w = nw;
	}

	std::cout << rv.size() << std::endl;

	for (auto &v : rv)
	{
		REP(i, 4)
			std::cout << (i?" ":"") << 1+v[i];
		std::cout << std::endl;
	}
}
