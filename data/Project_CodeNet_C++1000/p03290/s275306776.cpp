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
	
	for (int i = 0; i < n; i ++ )
	{
		cin >> p[i] >> c[i];
		c[i] /= 100;
	}
	
	int res = 0x3f3f3f3f;
	for (int t = 0; t < (1 << n); t ++ )
	{
		int cnt = 0, s = m;
		for (int i = 0; i < n; i ++ )
			if ((t >> i) & 1)
			{
				s -= p[i] * (i + 1) + c[i];
				cnt += p[i];
			}
			
		for (int i = n - 1; i >= 0; i -- )
			if (s > 0 && !((t >> i) & 1))
			{
				int c = min(s / (i + 1), p[i] - 1);
				cnt += c;
				s -= c * (i + 1);
			}
		
		if (s <= 0) res = min(res, cnt);
	}
	
	cout << res << endl;
	return 0;
}