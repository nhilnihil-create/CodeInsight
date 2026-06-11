#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HI;
typedef priority_queue<int, vector<int>, greater<int> > HDI;

const int N = 100010, M = 1010;

int n, m;
int a[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	
	int res = 0;
	for (int l = 0; l <= min(n, m); l ++ )
		for (int r = 0; r <= min(n - l, m - l); r ++ )
		{
			int t = m - l - r, sum = 0;
			HDI heap;
			for (int i = 0; i < l; i ++ )
			{
				heap.push(a[i]);
				sum += a[i];
			}
			for (int i = n - 1; i >= n - r; i -- )
			{
				heap.push(a[i]);
				sum += a[i];
			}
			while (t > 0 && heap.size() && heap.top() < 0)
			{
				sum -= heap.top();
				heap.pop();
				t -- ;
			}
			res = max(res, sum);
		}
		
	cout << res << endl;
    return 0;
}
