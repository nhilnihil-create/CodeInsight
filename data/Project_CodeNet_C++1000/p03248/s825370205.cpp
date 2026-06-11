#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char inp[100005];

int main() {
	scanf("%s", inp + 1);
	int N = strlen(inp + 1);
	if (inp[N] == '1' || inp[1] == '0') return !printf("-1");
	for (int i = 1; i < N; i++) {
		if (inp[i] != inp[N - i]) return !printf("-1");
	}
	int used = 1;
	for (int i = 2; i < N; i++) {
		if (inp[i] == '1') {
			while (used < i) printf("%d %d\n", used++, i);
		}
	}
	printf("%d %d\n", N - 1, N);
}