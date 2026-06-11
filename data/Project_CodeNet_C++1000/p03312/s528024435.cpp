#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[200005], n;
ll sum[200005], ans = 100000000000000;
int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", a + i);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int j = 3; j < n; j++)
	{ 
		ll m1 = lower_bound(sum + 1, sum + j, sum[j - 1] / 2) - sum;
		if (abs(sum[m1] - (sum[j - 1] - sum[m1])) > abs(sum[m1 - 1] - (sum[j - 1] - sum[m1 - 1])))
		{
			m1 = m1 - 1;
		}
		ll n1 = min(sum[m1], sum[j - 1] - sum[m1]);
		m1 = max(sum[m1], sum[j - 1] - sum[m1]);
		ll m2 = lower_bound(sum + j, sum + n + 1, sum[j - 1] + (sum[n] - sum[j - 1])/ 2) - sum;
		//cout << "*" << sum[j - 1] + (sum[n] - sum[j - 1])/ 2 << "* ";
		if (abs(sum[m2] - sum[j - 1] - (sum[n] - sum[m2])) > abs(sum[m2 - 1] - sum[j - 1] - (sum[n] - sum[m2 - 1])))
		{
			m2 = m2 - 1; 
		}
		ll n2 = min(sum[m2] - sum[j - 1], sum[n] - sum[m2]);
		m2 = max(sum[m2] - sum[j - 1], sum[n] - sum[m2]);
		//cout << m1 << "*" << n1 << "*" << m2 << "*" << n2 << endl;
		ans = min(max(m1, m2) - min(n1, n2), ans);
	}
	cout << ans << endl;
}