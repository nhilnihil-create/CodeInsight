#include<cstdio>
#include<iostream>
using namespace std;

string S[110];
int P[110];
int order[110];

void allSwap(int a) {
	swap(S[a], S[a + 1]);
	swap(P[a], P[a + 1]);
	swap(order[a], order[a + 1]);
}
int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> P[i];
		order[i] = i + 1;
	}

	int j = N - 1;
	while(j > 0) {
		for (int i = 0; i < j; i++) {
			if (S[i] > S[i + 1]) {
				allSwap(i);
			} else if (S[i] == S[i + 1] && P[i] < P[i + 1]) {
				allSwap(i);
			}
		}
		j--;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", order[i]);
	}

	return 0;
}
