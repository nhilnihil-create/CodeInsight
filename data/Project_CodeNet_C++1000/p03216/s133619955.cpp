#include<iostream>
using namespace std;
string s;
int n,q,k;
main()
{
	cin>>n>>s>>q;
	while(cin>>k)
	{
		long cd=0,cm=0,c=0,a=0;
		for(int i=0;i<n;i++)
		{
			if(i>=k)
			{
				if(s[i-k]=='D')cd--,c-=cm;
				else if(s[i-k]=='M')cm--;
			}
			if(s[i]=='D')cd++;
			else if(s[i]=='M')cm++,c+=cd;
			else if(s[i]=='C')a+=c;
		}
		cout<<a<<endl;
	}
}
