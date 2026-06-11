#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	int N, H;
	int a, b[MAX];
	int maxa = INT_MIN;
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		cin >> a >> b[i];
		maxa = max(maxa, a);
	}
	sort(b, b + N);
	int ans = 0;
	int sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (sum >= H) {
			break;
		}
        if (b[i] < maxa) {
            continue;
        }
		sum += b[i];
		ans++;
	}
	if (sum < H) {
		ans += (H - sum) / maxa + ((H - sum) % maxa == 0 ? 0 : 1);
	}
	cout << ans << endl;
	return 0;
}