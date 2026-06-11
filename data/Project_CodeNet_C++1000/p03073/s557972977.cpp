#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	
	cin>>s;
	int n=(int)s.size();
	int an=INT_MAX,c=0;
	for(int i=0;i<n;i++)
	if(i&1 && s[i]=='1')c++;
	else if((i&1) == 0 && s[i]=='0')c++;
	an=c;c=0;
	
	for(int i=0;i<n;i++)
	if(i&1 && s[i]=='0')c++;
	else if((i&1) == 0 && s[i]=='1')c++;
	cout<<min(an,c)<<endl;
	
	

}

