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
	int n, a, b;
	ll ans = 0LL;
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++)
	{
		int _i = i;
		int count = 0;
		while (_i)
		{
			count += _i % 10;
			_i /= 10;
		}
		if (count >= a && count <= b) ans += (ll)i;
	}

	cout << ans;
	return 0;
}