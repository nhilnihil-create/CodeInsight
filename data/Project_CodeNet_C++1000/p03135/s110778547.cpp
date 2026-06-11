#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int T,x; cin >> T >> x ;


	long double ans = (long double)T / x;
	printf("%.10Lf\n", ans);
	return 0;
}
