#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, m;
LL s[N];
map<int, int> h;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
	}
	
	h[0] = 1;
	LL res = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (h.count(s[i] % m)) res += h[s[i] % m];
		h[s[i] % m] ++ ;
	}
	
	printf("%lld\n", res);
	return 0;
}