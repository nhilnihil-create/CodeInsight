#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	ll storeNum, drink, ans = 0, sum = 0;
	cin >> storeNum >> drink;
	vector<pair<ll, ll>> a(storeNum);
	rep(i, storeNum)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	
	rep(i, storeNum)
	{
		if (sum + a[i].second <= drink)
		{
			ans += a[i].first * a[i].second;
			sum += a[i].second;
		}
		else
		{
			ans += (drink - sum) * a[i].first;
			sum += drink - sum;
		}
		if (sum >= drink) break;
	}
	cout << ans << endl;
	return 0;
}