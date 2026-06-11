#include <bits/stdc++.h>

typedef long long LL;

LL A, B, N;

int main() {
	
	std :: cin >> N >> A >> B;

	if(A * B < N || A + B - 1 > N) return puts("-1"), 0;

	while(N) {
		int x = std :: min(N - B + 1, A);
		for(LL i = N - x + 1; i <= N; i++) printf("%lld ", i);
		N -= x; B--;
	}

	std :: cout << std :: endl;

	return 0;
}
