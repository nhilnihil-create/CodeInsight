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
int p[N], c[N];

int main()
{
	cin >> n >> m;
	m /= 100;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> p[i] >> c[i];
		c[i] /= 100;
	}
	
	int res = 0x3f3f3f3f;
	for (int i = 0; i < 1 << 10; i ++ )
	{
		int sum = 0, tot = m;
		for (int j = 1; j <= 10; j ++ )
			if ((i >> (j - 1)) & 1)
			{
				sum += p[j];
				tot -= p[j] * j + c[j];
			}
		for (int j = n; j; j -- )
			if (tot > 0 && !((i >> (j - 1)) & 1))
			{
				int need = (tot + j - 1) / j;
				if (need <= p[j] - 1)
				{
					sum += need;
					tot = 0;
				}
				else
				{
					sum += p[j] - 1;
					tot -= (p[j] - 1) * j;
				}
			}
		if (tot <= 0) res = min(res, sum);
	}
	cout << res << endl;
    return 0;
}