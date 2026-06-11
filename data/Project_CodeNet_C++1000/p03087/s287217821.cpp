#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q,c=0;
	string s;
	cin >> n >> q >> s;
	vector<int> d(n,0);
	for(int i=0;i<n;i++)
	{
		if(s.at(i)=='A'&&i+1<n)
		{
          d.at(i)=c;
			if(s.at(i+1)=='C')
			{
				c++;
				i++;
				d.at(i)=c;
			}
		}
		else
		{
			d.at(i)=c;
		}
	}
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin >> l >> r;
		cout << d.at(r-1)-d.at(l-1) << endl;
	}
	return 0;
}
