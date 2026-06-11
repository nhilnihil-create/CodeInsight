#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int a,b; cin >> a >> b;

	double ans = (double)(a+b) / 2;
	cout << ceil(ans) << endl;
	return 0;
}
