#include <bits/stdc++.h>

using namespace std;

int n;
long long arr[100005];
vector<pair<int,int> > v;

int main()
{
	cin >> n;
	int mn=0,mx=0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		if(arr[i]<arr[mn]) mn=i;
		if(arr[i]>arr[mx]) mx=i;
	}
	if(mn==mx)
	{
		cout << 0 << endl;
		return 0;
	}
	int cur=(abs(arr[mn])>abs(arr[mx])?mn:mx);
	cur++; // wut?
	cout << (n-1)*2 << endl;
	for(int i=1;i<=n;i++)
	{
		if(i!=cur)
			cout << cur << " " << i << endl;
	}
	if(arr[cur-1]>0) // wut?
		for(int i=1;i<n;i++)
		{
				cout << i << " " << i+1 << endl;
		}
	else
		for(int i=n;i>1;i--)
			cout << i << " " << i-1 << endl;
}