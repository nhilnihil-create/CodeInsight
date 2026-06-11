#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;


int	n,k, a[200001];
int	t[200001],tc=0;


int main()
{
	cin >>n >>k;

	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}

	memset(t,0,sizeof(int)*(n+1));

	for(int i=0; i<n;i++)
	{
		t[a[i]]++;
	}

	int ans=0;

	sort(t,t+n+1);

	for(int i=0;i<k;i++)
	{
		ans+=t[n-i];
	}

	cout << (n-ans);

	return 0;
}