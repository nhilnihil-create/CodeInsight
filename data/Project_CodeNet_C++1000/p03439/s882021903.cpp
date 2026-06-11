#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	int l = 0, r = n;

	string v = "Vacant",m = "Male",f = "Female";

	string one;

	cout << 0 << endl;
	cin >> one;
	if(one==v)
	{
		return 0;
	}
	while(1)
	{
		int m = (r+l)/2;
		cout << m << endl;
		string s;
		cin >> s;
		if(s==v)return 0;

		if(m%2==0)
		{
			if(s==one)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}
		else if(m%2==1)
		{
			if(s==one)
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
	}
}
