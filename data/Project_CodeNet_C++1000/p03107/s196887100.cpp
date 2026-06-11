#include <bits/stdc++.h>
using namespace std; 

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin>>s;
	int o=0,n=s.length();
	for (int i = 0; i < n; i++)if(s[i]=='1')o++;
	if(o==0 || n-o==0)return cout<<0,0;
	cout<<2*min(o, n - o);
}