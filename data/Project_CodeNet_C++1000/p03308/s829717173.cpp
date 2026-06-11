#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	vector <int> a(n);
	rep(i, n)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a.back() - a.front() << endl;
	return 0;
}
