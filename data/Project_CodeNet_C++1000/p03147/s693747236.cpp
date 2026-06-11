
// C - Grand Garden

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int H[100];
int h[100];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> H[i];
	}

	int ans = 0;
	while(1) {
		bool finish = true;

		for (int i=0; i<N; i++) {
			if (h[i] < H[i]) {
				finish = false;
				ans++;
				for (int j=i; j<N; j++) {
					if (h[j] < H[j]) h[j]++;
					else break;
				}

				if (finish == false) break;
			}
		}

		if (finish) break;
	}

	cout << ans << endl;

	return 0;
}