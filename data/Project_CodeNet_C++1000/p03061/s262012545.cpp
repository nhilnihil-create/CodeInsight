#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,g=0;
	cin >> n;
	vector<int> a(n),b(n),c(n);
	for(int i=0;i<n;i++)
	{
		cin >> a.at(i);
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			b.at(i)=a.at(i);
			c.at(n-1-i)=a.at(n-1-i);
		}
		else if(i==1)
		{
			b.at(i)=gcd(a.at(i-1),a.at(i));
			c.at(n-1-i)=gcd(a.at(n-1),a.at(n-1-i));
		}
		else
		{
			b.at(i)=gcd(b.at(i-1),a.at(i));
			c.at(n-1-i)=gcd(c.at(n-i),a.at(n-1-i));
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			g=max(g,c.at(i+1));
		}
		else if(i==n-1)
		{
			g=max(g,b.at(i-1));
		}
		else
		{
			g=max(g,gcd(b.at(i-1),c.at(i+1)));
		}
	}
	cout << g << endl;
	return 0;
}
