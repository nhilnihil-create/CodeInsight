#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char s[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>s[i][j];
		}
	}
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		int f=1;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (s[(k+j)%n][(j+i)%n]!=s[(j)%n][(k+j+i)%n])
				{
					f=0;
				}
			}
		}
		if (f)
		{
			ans+=n;
		}
	}
	cout<<ans<<endl;
	return 0;
}
