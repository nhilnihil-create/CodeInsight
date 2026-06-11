#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int main()
{
	string s;
	cin>>s;
	int ans=0;
	rep(i,4)
		if(s[i]-'0'==2)
			ans++;
	cout<<ans<<endl;
	return 0;
}