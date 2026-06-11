//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include<iomanip>

using namespace std;
 
const long long N = 2e5 + 5;
long long a[N];
long long n;
long long ans = 0;
 
int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (a[0] != 0)
	{
		cout << -1;
		exit(0);
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1] && a[i] - a[i - 1] > 1)
		{
			cout << -1;
			exit(0);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			if (a[i] == a[i - 1] || a[i] < a[i - 1])
			{
				ans += a[i];
			}
			else
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}
	
            


 
