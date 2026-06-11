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
PII a[N];

bool cmp(PII a, PII b)
{
	if (a.S != b.S) return a.S < b.S;
	else return a.F > b.F;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l ++ ;
		a[i] = {l, r};
	}
	sort(a, a + m, cmp);
	
	int res = 0, pos = -0x3f3f3f3f;
	for (int i = 0; i < m; i ++ )
		if (a[i].F > pos)
		{
			pos = a[i].S;
			res ++ ;
		}
	
	printf("%d\n", res);
    return 0;
}