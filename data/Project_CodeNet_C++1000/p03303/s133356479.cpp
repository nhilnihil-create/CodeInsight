#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

char str[N];
int len;
int w;

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	scanf("%s", str);
	len = strlen(str);
	scanf("%d", &w);
	for (int at = 0; at < len; at += w) {
		printf("%c", str[at]);
	}

	return 0;
}