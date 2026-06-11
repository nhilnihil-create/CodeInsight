#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int inp[100005];
ll comb[1005][1005];
int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", inp + i);
	}
	sort(inp + 1, inp + N + 1);
	int n = inp[N], r;
	int gap = 2e9;
	for (int i = 1; i <= N; i++) {
		if (gap > abs((n + 1)/ 2 - inp[i])) {
			gap = abs((n + 1)/ 2 - inp[i]);
			r = inp[i];
		}
	}
	printf("%d %d", n, r);
}