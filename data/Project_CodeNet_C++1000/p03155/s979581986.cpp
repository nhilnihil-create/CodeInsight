#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, H, W;
	scanf("%d %d %d", &N, &H, &W);
	printf("%d\n", (N - H + 1) * (N - W + 1));
	return 0;
}
