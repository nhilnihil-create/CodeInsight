#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> A(N), B(N), C(N);
	for (ll i = 0; i < N; ++i) {cin >> A[i];}
	for (ll i = 0; i < N; ++i) {cin >> B[i];}

	if (accumulate(A.begin(), A.end(), 0ll) < accumulate(B.begin(), B.end(), 0ll))
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	vector<ll> A_B, B_A;
	for (ll i = 0; i < N; ++i)
	{
		if (A[i] < B[i])
			B_A.push_back(B[i] - A[i]);
		else
			A_B.push_back(A[i] - B[i]);
	}

	
	ll res = B_A.size();
	ll S = accumulate(B_A.begin(), B_A.end(), 0ll);

	sort(A_B.begin(), A_B.end());

	while (S > 0)
	{
		S -= A_B.back();
		A_B.pop_back();
		++res;
	}
	std::cout << res << std::endl;
}
