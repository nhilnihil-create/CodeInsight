#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt" , "r" , stdin);
	// freopen("output.txt" , "w" , stdout);
	// #endif

	ll n,c=0,c1=0,c2=0,c3=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(ll i=0;i<s.length()-1;i++)
		{
			if(s[i]=='A'&&s[i+1]=='B')
				c++;
		}
		if(s[0]=='B'&&s[s.length()-1]=='A')
			c1++;
		else if(s[0]=='B')
			c2++;
		else if(s[s.length()-1]=='A')
			c3++;
	}
	c=c+min(c2,c3);
	if(c1>0)
	{
	  c2-=min(c2,c3);
	  c3-=min(c2,c3);
	  if(c2||c3)
	  c+=c1;
	  else
	  	c+=c1-1;
	}
	cout<<c<<endl;


	
	
}
