#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, k;
	string s;
	long long ans, cnt, tmp;
	vector<long long> sum;
	char look;

	cin >> n >> k >> s;
	look = '1';
	cnt = 0;
	rep(i, n)
	{
		if (look == s[i])
			cnt++;
		else
		{
			sum.push_back(cnt);
			look = s[i];
			cnt = 1;
		}
	}
	if (cnt != 0) 
		sum.push_back(cnt);
	if (s[n - 1] == '0') 
		sum.push_back(0);
	rep(i, sum.size() - 1) 
		sum[i + 1] += sum[i];

	ans = sum[0];
	for(int i = 0; i < sum.size(); i+=2)
	{
		int index  = min((int)i + 2 * k, (int)sum.size() - 1);
		tmp = sum[index];
		if (i - 1 >= 0)
			tmp -= sum[i - 1];
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
