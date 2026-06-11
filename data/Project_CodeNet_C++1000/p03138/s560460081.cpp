#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <functional>
#include <queue>
#include <cmath>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rep1(i,n) for(int i=1;i<=(int)n;++i)

int N, K;
int A[100010];
int bit_counter[41];
int sum[41];

// 0-indexed sum[l, r]
int get_sum(int l, int r)
{
	return sum[r] - (l == 0 ? 0 : sum[l-1]);
}

signed main()
{
	cin >> N >> K;

	int left = -1;
	rep(i, 40) if (K & (1ll << i)) left = i;

	rep(i, N) cin >> A[i];

	if (left == -1) {
		int ans = 0;

		rep(i, N) ans += A[i]^0;

		cout << ans << endl;

		return 0;
	}

	rep(i, N) {
		rep(j, 40) {
			if(A[i] & (1ll << j)) {
				bit_counter[j]++;
			}
		}
	}

	rep(i, 40) {
		sum[i] = max(bit_counter[i], (N - bit_counter[i])) * (1ll << i);
		if (i) sum[i] += sum[i-1];
	}

	int a = 0;
	for (int i = 40; i > left; --i) {
		a += bit_counter[i] * (1ll << i);
	}

	int ans = a;
	for (int i = left; i >= 0; --i) {
		if (K & (1ll << i)) {
			ans = max(ans, a + bit_counter[i] * (1ll << i) + get_sum(0, i-1)); // not use
			a += (N - bit_counter[i]) * (1ll << i);
		} else {
			a += bit_counter[i] * (1ll << i);
		}

		ans = max(ans, a);
	}

	cout << ans << endl;
}
