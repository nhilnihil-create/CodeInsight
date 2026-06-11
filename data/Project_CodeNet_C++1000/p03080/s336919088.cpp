	#include <bits/stdc++.h>
	using namespace std;
	int main(int argc, char const *argv[])
	{
		string s;
		int r = 0,b = 0;
		int n;
		cin>>n>>s;
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] =='R') r++;
			else b++;
		}
		if (r>b) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		return 0;
	}