#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxN = 3 * 1e5 + 5;
int ans[maxN], tot;
ll N, A, B;
int main() {
	scanf("%lld%lld%lld", &N, &A, &B);
	if(A + B - 1 <= N && N <= A * B) {
		for(int i = N - A + 1; i <= N; ++i) ans[++tot] = i;
		N -= A;
		for(int i = B - 1; i >= 1; --i) {
			int t = min(N - i + 1, A);
			for(int j = N - t + 1; j <= N; ++j)
			ans[++tot] = j;
			N -= t;
		}
		for(int i = 1; i <= tot; ++i) printf("%d ", ans[i]);
	} else {
		printf("-1\n");
	}
}