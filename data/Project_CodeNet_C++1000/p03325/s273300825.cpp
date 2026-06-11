#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x;
	int ans=0;
	while(n--)
	{
		cin>>x;
		if(x%2==0)
		{
			while(x%2!=1)
			{
				x/=2;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
