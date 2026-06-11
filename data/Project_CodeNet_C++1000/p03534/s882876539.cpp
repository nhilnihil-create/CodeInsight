#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];
int cnt[26];
int main() {
	scanf("%s", s);
	int n = (int) strlen(s);
	for (int i = 0; i < n; ++ i) cnt[s[i] - 'a'] ++;
	int tmp = *max_element(cnt, cnt + 26);
	if ((tmp - 1) * 3 > n - 1) puts("NO"); else puts("YES");
}
