#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100100;
const int MOD = (int) 1e9 + 7;

int n, c[100];
char s[N];

int main() {

	scanf("%d %s", &n, s);

	memset(c, 0, sizeof c);

	for (int i = 0; i < n; i++) {
		c[s[i] - 'a']++;
	}

	long long res = 1;

	for (int i = 0; i < 26; i++) {
		res = res * (c[i] + 1) % MOD;
	}

	printf("%lld\n", (res + MOD - 1) % MOD);

	return 0;

}