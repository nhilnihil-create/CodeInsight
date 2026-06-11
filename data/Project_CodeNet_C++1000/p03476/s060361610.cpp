#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<time.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
#define INF (1<<30)
#define INFLL (1LL << 60)
#define MOD 1000000007
#define rep(i, n) for(int i=0; i<(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

#define PRIME_RANGE 100001
bitset<PRIME_RANGE> isPrime;
void calcPrime() {
	for (int i = 2; i < PRIME_RANGE; ++i) isPrime.set(i);
	for (int i = 2; i < PRIME_RANGE; ++i) {
		if (isPrime[i]) {
			for (int j = i * 2; j < PRIME_RANGE; j += i) {
				isPrime.reset(j);
			}
		}
	}
}

int main()
{
	int Q; cin >> Q;
	vector<int> accum(PRIME_RANGE + 1, 0);
	vector<int> like(PRIME_RANGE, 0);
	calcPrime();
	for (int i = 2; i < PRIME_RANGE; ++i) {
		if (isPrime[i] && isPrime[(i + 1) / 2]) {
			like[i] = 1;
			++accum[i];
		}
		accum[i + 1] = accum[i];
	}
	rep(i, Q) {
		int l, r; cin >> l >> r;
		cout << accum[r] - accum[l - 1] << endl;
	}

	return 0;
}
