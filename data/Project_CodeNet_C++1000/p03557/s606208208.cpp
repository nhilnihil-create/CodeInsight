#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n),b(n),c(n);

	for (int i=0;i<n;++i)
	{
		cin >> a[i];
	}
	for (int i=0;i<n;++i)
	{
		cin >> b[i];
	}
	for (int i=0;i<n;++i)
	{
		cin >> c[i];
	}

	sort(b.begin(),b.end());
	sort(c.begin(),c.end());

	int sum=0;
	map<int,int> mc;
	const int max_size=1000000000+1;
	mc[max_size]=0;
	for (auto it=c.rbegin();it!=c.rend();++it)
	{
		++sum;
		mc[*it]=sum;
	}

	map<int,int64_t> mb;
	int64_t count=0;
	mb[max_size]=0;
	for (auto it=b.rbegin();it!=b.rend();++it)
	{
		count+=(mc.upper_bound(*it))->second;
		mb[*it]=count;
	}

	count=0;
	for (int i=0;i<n;++i)
	{
		count+=(mb.upper_bound(a[i]))->second;
	}
	cout << count << endl;
}





