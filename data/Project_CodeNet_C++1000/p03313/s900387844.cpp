#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
ll max1[1 << 18], max2[1 << 18];
void update(int index, ll val) {
	if (max1[index] < val) {
		max2[index] = max1[index];
		max1[index] = val;
	}
	else if (max2[index] < val) {
		max2[index] = val;
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < (1 << N); i++) cin >> max1[i];
	for (int i = 0; i < N; i++) {
		for (int bit = 0; bit < (1 << N); bit++) {
			if (bit >> i & 1) {
				update(bit, max1[bit ^ (1 << i)]);
				update(bit, max2[bit ^ (1 << i)]);
			}
		}
	}
	ll prev = 0;
	for (int i = 1; i < (1 << N); i++) {
		ll now = max(prev, max1[i] + max2[i]);
		cout << now << endl;
		prev = now;
	}
}
