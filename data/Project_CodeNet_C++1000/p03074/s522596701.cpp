#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 110;

int n, k;
LL s[N];
char g[N];
vector<int> seq;

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", g);
	seq.push_back(0);
	for (int i = 0; i < n; i ++ )
	{
		int j = i, cnt = 0;
		while (j < n && g[i] == g[j]) j ++ , cnt ++ ;
		seq.push_back(cnt);
		i = j - 1;
	}
	
	int m = seq.size() - 1;
	for (int i = 1; i <= m; i ++ ) s[i] = s[i - 1] + seq[i];
	int st = g[0] == '0' ? 1 : 2, ed = max(min(m, st + 2 * k - 1), st);
	// cout << s[0] << endl;
	LL res = 0;
	for (int i = st, j = ed; i <= m; i += 2, j = min(j + 2, m))
	{
		// cout << i << ' ' << j << ' ';
		// cout << s[min(0, i - 2)] << ' ' << s[j] << endl;
		res = max(res, s[j] - s[max(1, i - 1) - 1]);
	}
	printf("%lld\n", max(res, s[1]));
	return 0;
}