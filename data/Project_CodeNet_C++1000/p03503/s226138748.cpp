#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> f(n,vector<int>(10,0)),
	p(n,vector<int>(11,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin >> f.at(i).at(j);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<11;j++)
		{
			cin >> p.at(i).at(j);
		}
	}
	int ans = -1000000000;
	for(int i=1;i<1024;i++)
	{
		vector<int> op(10,0);
		for(int j=0;j<10;j++)
		{
			int j1 = pow(2,j+1),
			    j2 = pow(2,j);
			if(i % j1 >= j2)
			{
				op.at(j) = 1;
			}
		}
		int pf = 0;
		int cnt =0;
		for(int j =0;j<n;j++)
		{
			cnt =0;
			for(int k=0;k<10;k++)
			{
				if(op.at(k) == 1 && 
				   f.at(j).at(k) == 1 )
				{
					cnt++;
				}
			}
			pf += p.at(j).at(cnt);
		}
		ans = max(ans,pf);
	}
    cout << ans << endl;
}
