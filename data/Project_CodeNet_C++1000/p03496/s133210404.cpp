
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <string.h>
#include <math.h>
#define ll long long
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int maxe,mine,max_pos,min_pos;
	maxe = -10000005,max_pos = 1;
	mine = -maxe,min_pos = 1;
	int num[55];
	for(int i=1;i<=n;i++)
		cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		if(maxe < num[i])
		{
			maxe = num[i];
			max_pos = i;
		}
		if(num[i] < mine)
		{
			mine = num[i];
			min_pos = i;
		}
	}
	cout<<n*2-2<<endl;
	if(abs(maxe) >= abs(mine))
	{
		for(int i=1;i<=n;i++)
		{
			if(i == max_pos);
			else
				cout<<max_pos<<" "<<i<<endl;
		}
		for(int i=2;i<=n;i++)
		{
			cout<<i-1<<" "<<i<<endl;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(i == min_pos);
			else cout<<min_pos<<" "<<i<<endl;
		}
		for(int i=n-1;i>=1;i--)
		{
			cout<<i+1<<" "<<i<<endl;
		}
	}
	return 0;
}
