#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < n; i++)

int main() {

	char S[123456];
	scanf("%s", S);
	int a = 0, b = 0, c = 0, l = 0;
	for (int i = 0; S[i] != '\0'; i++) {
		l++;
		switch (S[i])
		{
		case 'a':
			a++;
			break;
		case 'b':
			b++;
			break;
		case 'c':
			c++;
			break;
		default:
			break;
		}
	}

	if (max({ max(a, b) - min(a, b), max(b, c) - min(b, c), max(c, a) - min(c, a) }) <= 1) printf("YES\n");
	else printf("NO\n");

	return 0;
}