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
int a[N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	int res = 0;
	for (int l = 0; l <= min(n, m); l ++ )
		for (int r = 0; r <= min(n - l, m - l); r ++ )
		{
			vector<int> t;
			for (int i = 1; i <= l; i ++ ) t.PB(a[i]);
			for (int i = n, j = r; j; j -- , i -- ) t.PB(a[i]);
			
			sort(t.begin(), t.end());
			int sum = 0, cnt = m - l - r;
			for (auto u : t)
				if (cnt && u < 0) cnt -- ;
				else sum += u;
			
			res = max(res, sum);
		}
		
	cout << res << endl;
    return 0;
}