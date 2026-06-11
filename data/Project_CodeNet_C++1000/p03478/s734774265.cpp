#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		int num = i;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (A <= sum && sum <= B) {
			ans += i;
		}
	}
	printf("%d", ans);
	return 0;
}
