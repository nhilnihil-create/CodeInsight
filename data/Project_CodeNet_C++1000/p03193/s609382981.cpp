#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,h,w;
	cin>>n>>h>>w;
	int a,b,ans=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		if (h<=a&&w<=b)
		{
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
