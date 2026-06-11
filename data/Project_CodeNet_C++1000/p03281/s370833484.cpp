#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int x;
	scanf("%d",&x);
	int ans = 0;
	for (int i = 1; i <= x;i++){
		if (i % 2 == 0)continue;
		int count=0;
		for (int j = 1; j <= x; j++) {
			if (i % j == 0)count++;
		}
		if (count == 8)ans++;
	}
	printf("%d", ans);
}
