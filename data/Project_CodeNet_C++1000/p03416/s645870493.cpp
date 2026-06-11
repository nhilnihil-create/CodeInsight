#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int i,a,b,z=0;
	cin>>a>>b;
	for(i=a;i<=b;i++)
	{
		int n,x=0;
	    ostringstream str1; 
        str1 <<i; 
     	string s = str1.str(); 
		n=s.size();
		for(int j=0;j<n/2;j++)
		{
	
			if(s[j]==s[n-j-1])
			{
				x++;
			}
			else
			{
				break;
			}
		}
		if(x==n/2)
		{
			z++;
		}
	}
	cout<<z;
	
}