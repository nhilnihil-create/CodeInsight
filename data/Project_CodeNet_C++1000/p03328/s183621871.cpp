#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int a, b; cin >> a >> b;

	int d = abs(a-b);
	int ans = d * (d + 1) / 2; 
	cout << ans - b << endl;
	return (0);
}
