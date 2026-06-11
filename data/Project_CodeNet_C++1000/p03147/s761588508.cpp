#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n,0);
	for(int i = 0;i < n;i++)
	{
		cin >> h.at(i);
	}
	int c=0;
	for(int i=0;i<10000;i++)
	{
		int f=0;
		for(int j=0;j<n;j++)
		{
			if(h.at(j)>0)
			{
				h.at(j)--;
				f=1;
				if(j==n-1)
				{
					c++;
				}
				continue;
			}
			if(f==1&&h.at(j)==0)
			{
				c++;
				break;
			}
		}
		if(f==0)
		{
			break;
		}
	}
	cout << c << endl;
	return 0;
}
