#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n,i,x=0;
	n=s.size();
	if(s[0]!='A' || s[1]=='C'|| s[n-1]=='C')
	{
		cout<<"WA"<<endl;
		return 0;
	}
	for(i=1;i<n;i++)
	{
		int a;
		a=s[i]-0;
		if(s[i]=='C')
		{
			x++;
		}
		else if(a<96)
		{
			cout<<"WA"<<endl;
		    return 0;
		}
		
		
		if(x>=2)
		{
			cout<<"WA"<<endl;
		    return 0;
		} 
		
	}
	if(x==1)
	{
		cout<<"AC"<<endl;
	}
	else
	{
		cout<<"WA"<<endl;
	}
	
}