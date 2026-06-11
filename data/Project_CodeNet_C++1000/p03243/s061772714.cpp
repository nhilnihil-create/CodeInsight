#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()	
{
	int n;
	string s;
	stringstream ss;
	cin>>n;
	for(int i=n;i<=999;i++)
	{
		ss<<i;
		ss>>s;
		ss.clear();
		if(s[0]==s[1]&&s[1]==s[2])
		{
			cout<<s<<endl;
			return 0;
		}
	}
}