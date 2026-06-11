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
LL x[N], y[N], z[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++ ) cin >> x[i] >> y[i] >> z[i];
	
	LL res = 0;
	for (int i = 0; i < 1 << 3; i ++ )
	{
		vector<LL> t;
		for (int j = 0; j < n; j ++ )
		{
			LL sum = 0;
			if ((i >> 0) & 1) sum += x[j];
			else sum -= x[j];
			if ((i >> 1) & 1) sum += y[j];
			else sum -= y[j];
			if ((i >> 2) & 1) sum += z[j];
			else sum -= z[j];
			t.PB(sum);
		}
	
		sort(t.begin(), t.end());
		reverse(t.begin(), t.end());
		LL sum = 0;
		for (int j = 0; j < m; j ++ ) sum += t[j];
		res = max(res, sum);
	}
	cout << res << endl;
    return 0;
}