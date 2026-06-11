#include <bits/stdc++.h>
 
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int res = 0;
	int n;
	string s;
	int cntA = 0;
	int cntB = 0;
	int cntAB = 0;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> s;
		for(int j=0;j<s.length()-1;j++)
		{
			if(s.substr(j,2)=="AB")
			{
				res++;
			}
		}
		
		if(s[0]=='B' && s[s.length()-1]=='A')
		{
			cntAB++;
		}
		else if(s[0]=='B')
		{
			cntB++;
		}
		else if(s[s.length()-1]=='A')
		{
			cntA++;
		}		
	}

	//cout << res << ' ' << cntA << ' ' << cntB << '\n';
	if(cntAB > 0)
	{
		if(cntA > 0 && cntB > 0)
		{
			cntA--;
			cntB--;
			res += (cntAB +1);
		}
		else if(cntA > 0)
		{
			cntA--;
			res += (cntAB);
		}
		else if(cntB > 0)
		{
			cntB--;
			res += (cntAB);
		}
		else
		{
			res += (cntAB-1);
		}

	}
	res += min(cntA,cntB);
	
	cout << res << '\n';

	return 0;
}