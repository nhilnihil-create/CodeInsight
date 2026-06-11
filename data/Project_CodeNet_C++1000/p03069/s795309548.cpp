#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1ll << 60;

int main(int argc, char **argv)
{
	int n; cin >> n;
	string str; cin >> str;

	vector<ll> white_sum(n+1, 0), black_sum(n+1, 0);
	for (int i = 0; i < n; ++i)
	{
		black_sum[i+1] = black_sum[i] + (str[i] == '#' ? 1 : 0);
		white_sum[i+1] = white_sum[i] + (str[i] == '.' ? 1 : 0);
	}

	ll res{INF};
	for (int left = 0; left <= n; ++left)
	{
		ll tmp{0};
		tmp += black_sum[left];
		tmp += white_sum[n] - white_sum[left];
		res = min(res, tmp);
	}
	std::cout << res << std::endl;
}