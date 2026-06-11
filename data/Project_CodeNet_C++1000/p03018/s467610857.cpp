#include <bits/stdc++.h> 
using namespace std; 
#define int long long int
main() 
{ 
	string s;
	cin>>s;
	string ans="";
	int l=s.length();
	for(int i=0;i<l;i++)
	{
	    if(s[i]=='B' && i+1<l && s[i+1]=='C')
	    {
	        ans+='D';
	        i++;
	    }
	    else
	    {
	        ans+=s[i];
	    }
	}
	int count=0;
	int res=0;
	for(int i=ans.length()-1;i>=0;i--)
	{
	    if(ans[i]=='D')
	    {
	        //cout<<"heloo"<<endl;
	        count++;
	    }
	    else if(ans[i]=='A')
	    {
	        res+=count;
	    }
	    else
	    {
	        count=0;
	    }
	}
	cout<<res<<endl;
	return 0; 
} 
