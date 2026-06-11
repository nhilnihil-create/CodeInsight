#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int r,D;cin >> r >> D;
	int x0 ; cin >> x0;

	rep1(i, 10)
	{
		x0 = r*(x0) - D;
		cout <<  x0 << endl;
	}
	return (0);
}
