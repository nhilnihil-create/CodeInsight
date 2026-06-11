#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int l;
	cin>>l;
	--l;
	int n=0,m=0;
	++l;
	while (l>=(1<<n))
	{
		++n;
	}
	--l;
	m=(n-1)*2;
	vector<pair<pair<int,int>,int>> ans;
	for (int i = 0; i < n-1; ++i)
	{
		ans.push_back(make_pair(make_pair(i+1,i+2),0));
		ans.push_back(make_pair(make_pair(i+1,i+2),(1<<(n-i-2))));
	}
	int now=l-(1<<(n-1))+1;
	while (now>0)
	{
		++m;
		int r=0;
		while (now>=(1<<r))
		{
			++r;
		}
		--r;
		ans.push_back(make_pair(make_pair(1,n-r),l-now+1));
		now-=(1<<r);
	}
	cout<<n<<" "<<m<<endl;
	for (auto v:ans)
	{
		cout<<v.first.first<<" "<<v.first.second<<" "<<v.second<<endl;
	}
	return 0;
}
