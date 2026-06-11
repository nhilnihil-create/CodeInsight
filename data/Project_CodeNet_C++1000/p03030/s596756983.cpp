#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	pair<pair<string, int>, int> l[n];
	for(int i = 1; i <= n; i++) {
		string s; int p;
		cin >> s >> p;
		l[i - 1] = make_pair(make_pair(s, -p), i);
	}
	sort(l, l + n);
	rep(i, n) printf("%d\n", l[i].second);
	return 0;
}