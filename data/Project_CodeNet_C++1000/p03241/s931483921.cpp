#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 大きい順に並び替える
    sort(res.rbegin(), res.rend());
    return res;
}
int main() {
	ll N, M;
	cin >> N >> M;

	const auto &res = enum_divisors(M);
	ll ans = 1;
	for (int ii = 0; ii < res.size(); ++ii){
		if (M / res[ii] >= N){
			ans = res[ii];
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
