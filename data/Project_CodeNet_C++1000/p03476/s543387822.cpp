#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
typedef long long ll;
using namespace std;
#define INF (1 << 30)
#define INFLL (1LL << 60)
#define rep(i, n) for(int i=0; i<(n); ++i)

int main()
{
	const int ceil = 100000;
	vector<int> isPrime(ceil + 1, 1);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i < ceil + 1; ++i) {
		if (isPrime[i]) {
			for (int k = 2; i * k < ceil + 1; ++k) {
				isPrime[i * k] = 0;
			}
		}
	}
	vector<int> like(ceil + 1, 0), accumLike(ceil + 1, 0);
	for (int i = 2; i < ceil + 1; ++i) {
		if (isPrime[i]) {
			if (isPrime[(i + 1) / 2]) {
				like[i] = 1;
				++accumLike[i];
			}
		}
		accumLike[i] += accumLike[i - 1];
	}

	int Q; cin >> Q;
	vector<int> anss;
	rep(i, Q) {
		int l, r; cin >> l >> r;
		anss.push_back(accumLike[r] - accumLike[l - 1]);
	}
	rep(i, anss.size()) cout << anss[i] << endl;
	return 0;
}
