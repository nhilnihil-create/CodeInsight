#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	for(int i=0;i<h;i++)
	{
		cin >> s.at(i);
	}
	string ans = "Yes";
	for(int i = 0;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			int z1=0,z2=0,z3=0,z4=0;
			char nw = s.at(i).at(j);
			if(nw == '.')
			{
				continue;
			}
			//ue
			if(i - 1 >= 0)
			{
				if(s.at(i-1).at(j) == '.')
				{
					z1 = 1;
				}
			}
			else
			{
				z1 = 1;
			}
			//migi
			if(j + 1 < w)
			{
				if(s.at(i).at(j+1) == '.')
				{
					z2 = 1;
				}
			}
			else
			{
				z2 = 1;
			}
			//hida
			if(j - 1 >= 0)
			{
				if(s.at(i).at(j-1) == '.')
				{
					z3 = 1;
				}
			}
			else
			{
				z3 = 1;
			}
			//sita
			if(i + 1 < h)
			{
				if(s.at(i+1).at(j) == '.')
				{
					z4 = 1;
				}
			}
			else
			{
				z4 = 1;
			}
			//kekka
			if(z1*z2*z3*z4 == 1)
			{
				ans = "No";
			}
		}
	}
    cout << ans << endl;
	return 0;
}
