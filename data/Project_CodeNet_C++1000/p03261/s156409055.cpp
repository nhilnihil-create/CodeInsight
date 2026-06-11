#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,h=1,j=0;
    cin>>a;
    string s[a];
    for(int i=0;i<=a-1;i++)
    {
    	cin>>s[i]; 
	}
	for(int i=1;i<=a-1;i++)
	{
		for(int k=i-1;k>=0;k--)
		{
			if(s[i]==s[k])
			{
				h=0;
			} 
		}
		int len=s[i-1].length();
		if(s[i][0]==s[i-1][len-1])
		{
			j++; 
		} 
	}
	if(h==1&&j==a-1)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}
