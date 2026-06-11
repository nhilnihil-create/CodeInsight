#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,a,b)		for(int i=a;i<=b;i++)

string s;
map<char,int> m;
int cnt=0;
int main() 
{ 

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag = false;
    cin>>s;
    rep(i,0,s.length()-1)
    {
    	m[s[i]]+=1;
    	if(isupper(s[i]))
    		cnt++;
    }
    if(cnt==2)
	    {
	    if(s.front()=='A')
	    {
	    	if(m['C']!=1)
	    	{
	    		cout<<"WA";
	    	}
	    	else
	    	{
	    		rep(i,2,s.length()-2)
	    		{
	    			if(s[i]=='C')
	    				flag=true;
	    		}
	    		if(flag)
	    			cout<<"AC";
	    		else
	    			cout<<"WA";
	    	}
	    }
	    else
	    	cout<<"WA";
	}
	else
		cout<<"WA";

} 
