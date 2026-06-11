#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	vector <int> l(n);
	int sum = 0;
	rep(i, n)
	{
		cin >> l[i];
		sum += l[i];/* 全ての長さの合計 */
	}
	sort(l.begin(), l.end());
	sum -= l.back(); //辺の長さの合計 - 最長の辺
	if (l.back() < sum)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
