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
	ll N, K; cin >> N >> K;
	string S; cin >> S;

	ll left{0}, right{0};
	ll cnt{0};

	if (S[left] == '0') cnt = 1;
	while (right < N && cnt <= K)
	{
		if (S[right] == '1' && S[right+1] == '0') ++cnt;
		++right;
	}
	if (left + 1 == N)
	{
		std::cout << N << std::endl;
		return 0;
	}



	ll res{right - left};
	while (left < N && right < N)
	{
		++right;
		while (right < N && (S[right-1] != '1' || S[right] != '0')) {++right;}
		++left;
		while (left < N && (S[left-1] != '0' || S[left] != '1')) {++left;}

		// std::cout << "left : "  << left << std::endl;
		// std::cout << "right : " << right << std::endl;
		res = max(res, right - left);
	}

	std::cout << res << std::endl;
}
