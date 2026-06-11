#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n, k; cin >> n >> k;
	if (n % k)
		cout << 1 << endl;
	else if (n % k == 0)
		cout << 0 << endl;
	return 0;
}
