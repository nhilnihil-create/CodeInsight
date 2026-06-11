

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	int N, K; cin >> N >> K;
	vector<int> bkt(N, 0);
	for (int i = 0; i < N; ++i) {
		int a; cin >> a; --a;
		++bkt[a];
	}
	sort(bkt.begin(), bkt.end());
	auto ub = upper_bound(bkt.begin(), bkt.end(), 0);
	int kind = N - (ub - bkt.begin());
	int ans = 0;
	while (kind > K) {
		ans += *ub;
		++ub;
		--kind;
	}
	cout << ans << endl;
	return 0;
}
