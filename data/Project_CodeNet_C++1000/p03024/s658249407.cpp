#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	char inp[16];
	scanf("%s", inp);
	int len = strlen(inp);
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (inp[i] == 'o')
			cnt++;
	}
	if ((15 - len) + cnt >= 8)
		printf("YES\n");
	else
		printf("NO\n");
}