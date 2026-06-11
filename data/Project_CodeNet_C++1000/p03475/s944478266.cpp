#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
int c[Max], s[Max], f[Max];

int main()
{
	FAST;
	int n;
	cin >> n;
	for (int i = 1;i < n;i++)
	{
		cin >> c[i] >> s[i] >> f[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int ans = 0;
		for (int j = i;j < n;j++)
		{
			ans = max(ans, s[j]);
			if (ans % f[j] != 0)ans = ans + f[j] - ans % f[j];
			ans += c[j];
		}
		cout << ans << endl;
	}

}