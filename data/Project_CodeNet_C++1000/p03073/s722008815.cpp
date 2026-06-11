#include <bits/stdc++.h>
using namespace std;
int main()
{
	 string s;
	 cin>>s;
	 int i,n,x=0;
	 n=s.size();
	 for(i=1;i<n;i++)
	 {
	 	if(s[i]==s[i-1])
	 	{
	 		if(s[i]=='1')
			 {
			 s[i]='0';
			 }
			 else
			 {
			 	s[i]='1';
			 }
			 x++;
		}
	 }
	 cout<<x<<endl;
}