#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int L[100];
	for (int i = 0; i < N; i++) {
		scanf("%d", &L[i]);
	}
	sort(L, L + N);
	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += L[i];
	}
	printf(L[N - 1] < sum ? "Yes\n" : "No\n");
	return 0;
}
