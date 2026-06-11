#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int fb=-1;
	long long c = 0;
	for(int i=0;i<s.length();i++)
	{
			if(s[i]=='B'&&fb==-1)
				fb=i;
			else if(s[i]=='W'&&fb!=-1)
			{
				c = c + i-fb;
				fb++; 
			}

	}
	cout<<c<<"\n";
}