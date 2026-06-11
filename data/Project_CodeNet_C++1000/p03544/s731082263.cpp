#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <bitset>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<int64_t> A = { 2, 1 };

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 2; i < N + 1; i++) {
		A.push_back(A[i - 1] + A[i - 2]);
	}
	printf("%lld\n", A[N]);
}