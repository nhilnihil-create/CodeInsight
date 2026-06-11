#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int a,b,c; cin >> a >> b >> c;
	int ans = a+b+c;
	ans += max({a,b,c}) * 10;
	ans -= max({a,b,c});
	cout << ans << endl;
	return (0);
}