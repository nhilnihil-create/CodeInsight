#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	multiset<int> st;
	int d;
	for (int i = 0; i < n; ++i)
	{
		cin>>d;
		if (d==0)
		{
			cout<<"0\n";
			return 0;
		}
		st.insert(d);
	}
	for (int i = 1; i < 12; ++i)
	{
		if (st.count(i)>2)
		{
			cout<<"0\n";
			return 0;
		}
	}
	if (st.count(12)>1)
	{
		cout<<"0\n";
		return 0;
	}
	int f=0;
	vector<int> v;
	v.push_back(12);
	for (int i = 1; i < 12; ++i)
	{
		if (st.count(i)==2)
		{
			v.push_back(12-i);
			v.push_back(12+i);
		}
		else if (st.count(i)==1)
		{
			if (f%2==0)
			{
				v.push_back(12-i);
			}
			else
			{
				v.push_back(12+i);
			}
			++f;
		}
	}
	if (st.count(12)==1)
	{
		v.push_back(0);
		v.push_back(24);
	}
	sort(v.begin(), v.end());
	int ans=30;
	for (int i = 0; i < v.size()-1; ++i)
	{
		ans=min(ans,v[i+1]-v[i]);
	}
	if (v[0]!=0)
	{
		ans=min(ans,24-v[v.size()-1]+v[0]);
	}
	cout<<ans<<endl;
	return 0;
}
