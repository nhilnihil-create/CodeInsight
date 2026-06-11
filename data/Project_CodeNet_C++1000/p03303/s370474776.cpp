#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	int w;
	cin>>s>>w;
	string ans;
	for (int i = 0; i < s.size(); i+=w)
	{
		ans.push_back(s[i]);
	}
	cout<<ans<<endl;
	return 0;
}
