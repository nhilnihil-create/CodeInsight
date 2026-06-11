#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int tmp = N;
	int f = 0;
	while (tmp > 0) {
		f += tmp % 10;
		tmp /= 10;
	}

	printf(N % f == 0 ? "Yes\n" : "No\n");
	return 0;
}
