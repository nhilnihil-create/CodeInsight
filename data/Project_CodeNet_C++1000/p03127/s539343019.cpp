#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = 1000000000;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a.at(i);
	}
	sort(a.begin(),a.end());
	int b=a.at(0),c;
	for(int i=1;i<n;i++)
	{
		c=a.at(i);
		while(b>0)
		{
			int d= c%b;
			c = b;
			b = d;
		}
		b = c;
	}
	cout << b << endl;
	return 0;
}
