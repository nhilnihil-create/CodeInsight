#include <bits/stdc++.h>
 
using namespace std;
 
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	int n,k;
	long long int t;
	vector <long long int> v;
 
	cin >> n >> k;
 
	for(int i=0;i<n;i++)
	{
		cin >> t;
		v.push_back(t);
	}
 
	vector <unsigned long long int> v2;
 
	for(int i=0;i<n;i++)
	{
		unsigned long long int val = 0;
		for(int j=i;j<n;j++)
		{
			val += v[j];
			v2.push_back(val);
		}
	}
 
	sort(v2.rbegin(),v2.rend());
	
	unsigned long long int res = 0;
 
	for(long long int j=60;j>=0;j--)
	{
		vector <unsigned long long int> temp;
		int cnt = 0;
		for(int i=0;i<v2.size();i++)
		{
			if((v2[i]&(1LL << j)))
			{
				cnt++;
				temp.push_back(v2[i]);
			}
		}
		if(cnt >= k)
		{
			res += (1LL << j);
			v2 = temp;
		}
	}

	cout << res << '\n';

	return 0;
}
