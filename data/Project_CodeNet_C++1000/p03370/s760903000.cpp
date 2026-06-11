#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
 
using namespace std;
using vi=vector<int>;
using pii=pair<int, int>;
using ull=unsigned long long;
using ll=long long;
 
int main()
{
	int n, x; cin >> n >> x;
	vi m(n);
	int sum = 0, ans = -1;
	int mn = 999999;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
		if (m[i] < mn)
			mn = m[i];
	}

	for (int i = 0; i < n; i++)
	{
		if ((sum + m[i]) <= x)
		{
			sum += m[i];
			ans++;
		}
	}

	while (sum <= x){
		ans++;
		sum += mn;
	}

	cout << ans << "\n";

}
