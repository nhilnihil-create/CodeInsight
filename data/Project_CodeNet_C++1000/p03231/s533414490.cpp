#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD(ll a, ll b)
{
	if (b == 0) return a;
	else return GCD(b, a%b);
}


int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;
	string S, T; cin >> S >> T;

	
	bool flag{true};
	ll g = GCD(N, M);
	ll res = M / g * N;
	ll m = M / g;
	ll n = N / g;
	for (ll i = 0; i < g; ++i)
	{
		if (S[i*n] != T[i*m]) flag = false;
	}

	std::cout << (flag ? res : -1) << std::endl;
}
