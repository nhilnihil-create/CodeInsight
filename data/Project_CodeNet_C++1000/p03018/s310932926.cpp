#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;

char s[MAXN];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	ll ans = 0; int now = 0, pos = 1;
	while (pos <= n) {
		if (s[pos] == 'A') now++, pos++;
		else if (s[pos] == 'B' && s[pos + 1] == 'C') ans += now, pos += 2;
		else now = 0, pos++;
	}
	printf("%lld",ans);
	return 0;
}

