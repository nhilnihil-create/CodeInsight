#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv)
{
	ll N; cin >> N;

	vector<ll> v;
	v.reserve(40);
	ll i{0};
	for (; N != 0; ++i)
	{
		ll r = N % 2;
		if (r < 0) r += 2;
		v.push_back(r);
		N = (N - r) / (-2);
	}
	if (v.empty()) v.push_back(0);
	reverse(v.begin(), v.end());
	for (auto &e : v)
		std::cout << e;
	std::cout << std::endl;
}
