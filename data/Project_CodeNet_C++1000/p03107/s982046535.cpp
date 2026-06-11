#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int c0=0,c1=0;
	for(int i =0;i<n;i++)
	{
		if(s.at(i)=='0')
		{
			c0++;
		}
		else
		{
			c1++;
		}
	}
	int k;
	if(c0>c1)
	{
		k=c1*2;
	}
	else
	{
		k=c0*2;
	}
	cout << k << endl;
	return 0;
}
