#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int ans = 0;
	int i = 0;
	while (1) {
		if (i * i <= N) {
			ans = i * i;
		} else {
			break;
		}
		i++;
	}
	printf("%d\n", ans);
	return 0;
}
