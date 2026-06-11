#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
const int N_ = 200500;
 
int X[N_];
long long S[N_];
 
int main()
{
    int N, A; scanf("%d%d", &N, &A);
    for(int i = 1; i <= N; i++) scanf("%d", &X[i]);
 
		for(int i = 1; i <= N; i++) {
			S[i] = S[i-1] + X[i];
		}
 
		long long ans = 9e18;
		for(int k = 1; k <= N; k++) {
			// x_1 + 4x_1 + (9-4) x_2 + (16-9)x_3 + (25-16) x_4....
			// 5x_1 + 5x_2 + 7x_3 + 9x_4 + ...
			long long cur = (long long)A * (k + N);
			for(int i = N, c = 1; i > 0; i -= k, c += 1) {
				cur += (S[i] - S[max(i-k, 0)]) * (c == 1 ? 5 : 2 * c + 1);
				cur = min(cur, (long long)9e18);
			}
			ans = min(ans, cur);
		}
 
		printf("%lld\n", ans);
 
	return 0;
}