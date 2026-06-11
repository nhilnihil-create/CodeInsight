#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	a.push_back(0);
	for(int i = 0;i<n;i++)
	{
		int c;
		cin>>c;
		a.push_back(c);
	}
	a.push_back(0);
	int s = 0;
	for(int i = 0;i<=n;i++)
	{
		s+=abs(a[i]-a[i+1]);
	}
	//cout<<s<<endl;
	for(int i = 1;i<=n;i++)
	{
		int m = s;
		m-=(abs(a[i]-a[i-1])+abs(a[i+1]-a[i]));
		m+=abs(a[i+1]-a[i-1]);
		cout<<m<<endl;
	}
}