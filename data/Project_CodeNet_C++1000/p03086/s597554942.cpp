#include<bits/stdc++.h>
using namespace std;
bool check(char c)
{
	return c=='A'||c=='C'||c=='G'||c=='T';
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int fi=-1,se=-1;
	int ans=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(!check(s[i]))
		se=fi=i;
		else{
			fi=i;
			ans=max(ans,fi-se);
		}
	}
	cout<<ans<<endl;
    return 0;
}
