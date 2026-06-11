#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	vector<int> u, m, l;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		m.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		l.push_back(x);
	}
	sort(u.begin(),u.end());
	sort(m.begin(),m.end());
	sort(l.begin(),l.end());
	ll count=0;
	for(int i=0;i<n;i++)
	{
		auto itr1 = lower_bound(u.begin(),u.end(),m[i]);
		auto itr2 = upper_bound(l.begin(),l.end(),m[i]);
		count += (itr1-u.begin())*(l.end()-itr2);
	}

	cout<<count<<"\n";
}