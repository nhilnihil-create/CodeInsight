#include <bits/stdc++.h>
#define rep(i, n) for(int i =0;i  < (n); i++)
using namespace std;

int main(void)
{
	int n, a, b;
	int mx, mn;

	cin >> n >> a >> b;
	mx = min(a, b);
	mn = (a + b) - n;
	if (mn < 0)
		mn = 0;
	cout << mx << " " << mn << endl;
	return 0;
}
