#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	scanf("%d %d", &N, &M);

	int powm = 1;
	for (int i = 0; i < M; i++) {
		powm *= 2;
	}
	printf("%d", powm * (M * 1900 + (N - M) * 100));

	return 0;
}
