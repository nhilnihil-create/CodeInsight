#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char **argv)
{
	bool flag;

	int N;
	cin >> N;
	vector<ll> a(N+10);
	vector<ll> b(N+10);

	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];

	ll larger_a{0}, larger_b{0};
	for (int i = 0; i < N; ++i)
	{
		if (a[i] > b[i]) larger_a += a[i] - b[i];
		if (b[i] > a[i]) larger_b += (b[i] - a[i]) / 2;
	}

	if (larger_a <= larger_b) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
}
