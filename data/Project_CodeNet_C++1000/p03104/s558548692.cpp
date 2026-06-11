#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

ll f(ll n)
{
	ll tmp = (n+1)/2;
	ll res = tmp%2;
	if (n%2 == 0)
		res ^= n;
	return res;
}

int main(int argc, char **argv)
{
	ll A, B; cin >> A >> B;
	std::cout << (f(A-1)^f(B)) << std::endl;
}
