#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n;
	vector<int> out;
	if (n == 0) out.push_back(0);
	while (n != 0) 
	{
		if (n % 2 != 0)
		{
			out.push_back(1);
			n--;
		}
		else
			out.push_back(0);
		n /= -2; 
	}
	reverse(out.begin(), out.end());
	rep(i, out.size()) cout << out[i];
	cout << endl;
	return 0;
}
