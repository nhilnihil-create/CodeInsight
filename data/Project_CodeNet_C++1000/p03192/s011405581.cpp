#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	char n;
	int ans=0;
	for (int i = 0; i < 4; ++i)
	{
		cin>>n;
		if (n=='2')
		{
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
