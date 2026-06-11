#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,m;
	string s;
	cin>>n>>m>>s;
	s[m-1]+=32;
	cout<<s<<endl;
    return 0;
}
