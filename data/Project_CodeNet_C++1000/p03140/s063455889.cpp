#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string a,b,c;
	cin>>n>>a>>b>>c;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		set<char> d;
		d.insert(a[i]);
		d.insert(b[i]);
		d.insert(c[i]);
		ans+=d.size()-1;
	}
	cout<<ans<<endl;
	return 0;
}
