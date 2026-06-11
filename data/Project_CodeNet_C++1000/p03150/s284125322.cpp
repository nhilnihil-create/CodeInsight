#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,s1,s2;
	cin>>s;
	for(int t=0;t<=7;t++)
	{
		s1=s.substr(0,7-t);
		s2=s.substr(s.size()-t,t);
		if(s1+s2=="keyence")
		{ 
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}