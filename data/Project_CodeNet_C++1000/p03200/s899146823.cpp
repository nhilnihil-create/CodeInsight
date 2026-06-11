#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll>pairs;
int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	ll t,n,i,j,k,l,c,f;
	string s;
	cin>>s;
	c=0;
	f=0;
	for(i=0;i<s.length();i++)
	{
	    if(s[i]=='W')
	    f+=c;
	    else
	    c++;
	}
	cout<<f;
	return 0;
}
