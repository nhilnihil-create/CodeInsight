#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (x % y == 0) puts("-1");
	else printf("%d\n", x);
	return 0;
}
