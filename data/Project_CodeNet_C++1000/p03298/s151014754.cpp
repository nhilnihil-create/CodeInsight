#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
string S;

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};

using P = pair<string, string>;

void solve() {
	long long ans;
	cin >> N >> S;
	string S1, S2;
	S1 = S.substr(0, N);
	S2 = S.substr(N, N);
	reverse(S2.begin(), S2.end());

	unordered_map<P, int, pair_hash> um;
	for (int Nbits_i = 0; Nbits_i < 1 << N; Nbits_i++)
	{
		string A1 = "", B1 = "";
		for (int S1_i = 0; S1_i < N; S1_i++)
		{
			if (Nbits_i >> S1_i & 1) {
				A1 += S1[S1_i];
			}
			else {
				B1 += S1[S1_i];
			}
		}
		um[P(A1, B1)]++;
	}
	long long sum = 0;
	for (int Nbits_i = 0; Nbits_i < 1 << N; Nbits_i++)
	{
		string A2 = "", B2 = "";
		for (int S2_i = 0; S2_i < N; S2_i++)
		{
			if (Nbits_i >> S2_i & 1) {
				A2 += S2[S2_i];
			}
			else {
				B2 += S2[S2_i];
			}
		}
		sum += um[P(A2, B2)];
	}

	ans = sum;
	cout << ans << "\n";
}

int main() {
	solve();

	return 0;
}
