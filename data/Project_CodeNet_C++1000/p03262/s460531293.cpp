#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		int z;
		cin >> z;
		a.at(i) = abs(z-x);
	}
	sort(a.begin(),a.end());
	if(n==1)
	{
		cout << a.at(0) << endl;
		return 0;
	}
	int g=0;
	for(int i=0;i<n-1;i++)
	{
		int b=a.at(i+1),c=g,d=1;
		if(g==0)
		{
			c=a.at(i);
		}
		while(d != 0)
		{
			g = c;
			d = b%c;
			b = c;
			c = d;
		}
	}
	cout << g << endl;
	return 0;
}
