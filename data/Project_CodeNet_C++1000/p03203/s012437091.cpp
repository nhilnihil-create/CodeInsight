#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int H, W, N;
int mini[MAXN];

int main() {
	memset(mini, INF, sizeof mini);
	
	scanf("%d%d%d", &H, &W, &N);
	while (N--) {
		int x, y;
		scanf("%d%d", &x, &y);
		mini[x] = min(mini[x], y);
	}

	int curr = 1;	
	for (int i = 2; i <= H; i++) {
		if (mini[i] <= curr) {
			printf("%d\n", i - 1);
			return 0;
		}
		curr = min(curr + 1, mini[i] - 1);
	}
	
	printf("%d\n", H);
	
	return 0;
}