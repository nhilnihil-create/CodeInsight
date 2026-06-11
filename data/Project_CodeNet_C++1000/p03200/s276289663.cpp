#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	long int i,a=0,b=0,n;
	n=s.size();

		for(i=0;i<n;i++)
		{
			
			if(s[i]=='W')
			{
				b++;
				a=a+(i+1-b);
				
			}
		}
		cout<<a<<endl;
	

}