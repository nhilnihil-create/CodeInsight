#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int a[200005], b[200005];
int ans;
int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", b + i);
	}
	for (int bit = 0; bit < 30; bit++) {
		vector<int> va[2], vb[2];
		for (int i = 1; i <= N; i++) {
			va[bool(a[i] & (1 << bit))].push_back(a[i] & ((1 << bit) - 1));
			vb[bool(b[i] & (1 << bit))].push_back(b[i] & ((1 << bit) - 1));
		}
		sort(va[0].begin(), va[0].end());
		sort(vb[0].begin(), vb[0].end());
		sort(va[1].begin(), va[1].end());
		sort(vb[1].begin(), vb[1].end());
		bool tot = 0;
		int target = 1 << bit;
		for (int x : va[0]) {
			tot ^= (lower_bound(vb[1].begin(), vb[1].end(), target - x) - vb[1].begin()) & 1;
			tot ^= (vb[0].size() - (lower_bound(vb[0].begin(), vb[0].end(), target - x) - vb[0].begin())) & 1;
		}
		for (int x : va[1]) {
			tot ^= (lower_bound(vb[0].begin(), vb[0].end(), target - x) - vb[0].begin()) & 1;
			tot ^= (vb[1].size() - (lower_bound(vb[1].begin(), vb[1].end(), target - x) - vb[1].begin())) & 1;
		}
		if (tot) ans |= target;
	}
	printf("%d", ans);

}