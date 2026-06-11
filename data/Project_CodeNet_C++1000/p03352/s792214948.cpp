#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int x;
	cin >> x;
	int ans = 1;
	for(int i = 2;i<=x;i++)
	{
		for(int j = i*i;j<=x;j*=i)
		{
			if(j<=x)ans= max(ans,j);
		}
	}
	cout<<ans<<endl;
}