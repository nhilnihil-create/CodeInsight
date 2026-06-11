#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>c(n,0),s(n,0),f(n,0);
	for(int i = 0 ;i < n-1 ;i++)
	{
		cin >> c.at(i) >> s.at(i) >> f.at(i);
	}
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		cnt = s.at(i) + c.at(i);
		for(int j=i+1;j<n-1;j++)
		{
			if(s.at(j) >= cnt)
			{
				cnt = s.at(j) + c.at(j);
			}
			else
			{
				int z=(cnt - s.at(j)) / f.at(j);
				int zz = cnt % f.at(j),zzz;
				if(zz == 0)
				{
					cnt+=c.at(j);
				}
				else
				{
					cnt=c.at(j) + s.at(j) + f.at(j) * (z+1);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
