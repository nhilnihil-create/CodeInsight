#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 5;
int lst[Max];
int ls[Max];
ll sum1[Max], sum2[Max];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> lst[i];
		sum1[i] = sum1[i - 1] + lst[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> lst[i];
		sum2[i] = sum2[i - 1] + lst[i];
	}
	ll ans = 0;
	for (int i = 1;i <= n;i++)
	{
		ans = max(ans, sum1[i] + sum2[n] - sum2[i - 1]);
	}
	cout << ans;
}