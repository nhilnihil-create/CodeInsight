#include <cmath>
#include<iostream>
#include<vector>
/*#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>*/
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
vector<P> prime_factorize(long long N) {
	vector<pair<long long, long long> > res;
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0;
		while (N % a == 0) {
			++ex;
			N /= a;
		}
		res.push_back({ a, ex });
	}
	if (N != 1) res.push_back({ N, 1 });
	return res;
}

int main(void) {
	int n;
	cin >> n;
	ll count = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0)continue;
		vector<P>p;
		p = prime_factorize(i);
		ll index = 1;
		for (auto id : p) {
			index *= id.second + 1;
		}
		if (index == 8) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}