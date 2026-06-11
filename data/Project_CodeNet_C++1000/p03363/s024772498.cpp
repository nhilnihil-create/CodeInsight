#include <bits/stdc++.h> 
 
using namespace std; 

map <long long int,long long int> cnt;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	long long int t;
	long long int sum = 0;

	cin >> n;

	cnt[0]++;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		sum += t;
		cnt[sum]++;
	}

	long long int res = 0;

	for(auto it : cnt)
	{
		res += ((it.second)*(it.second - 1)/2);
	}

	cout << res << '\n';
	
	return 0;
}