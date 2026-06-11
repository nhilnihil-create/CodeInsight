#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; 
	int ans=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(s[i]=='+')ans++;
	else ans--;
	cout<<ans<<endl;
    return 0;
}
