#include <iostream>
#include <algorithm>
#include <limits>
#include <cassert>

using namespace std;

#define	MAXN 200000
int N, X;
int x;
long long sum_x[MAXN + 1];

void solve() {
	unsigned long long ans;
	cin >> N >> X;
	sum_x[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		sum_x[i] += sum_x[i - 1] + x;
	}

	unsigned long long E_min = numeric_limits<unsigned long long>::max();
	for (int k = 1; k <= N; k++) // k = (ゴミをゴミ箱に入れる回数)
	{
		unsigned long long E_k = 0;

		const int q_k = N / k;
		const int r_k = N % k;
		const int top_num_in_k_groups = q_k - 2;
		// from 1 to r
		E_k += max(0, top_num_in_k_groups + 1) * (sum_x[r_k] - sum_x[0]);
		for (int i = 0; i < top_num_in_k_groups; i++)
		{
			// from start_index within k
			const int num_i = top_num_in_k_groups - i;
			const int start_index = r_k + i * k;
			E_k += num_i * (sum_x[start_index + k] - sum_x[start_index]);
		}
		E_k *= 2;

		E_k += (long long)k * X; //ゴミ箱に入れる
		E_min = min(E_min, E_k);
	}
	E_min += 5 * sum_x[N];
	E_min += (long long)N * X;
	ans = E_min;

	cout << ans << endl;
	return;
}



int main() {
	solve();
	return 0;
}