#include <bits/stdc++.h>
using namespace std; 

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,q;cin>>n>>q;
	string s;cin>>s;
	int t[n];t[0]=0;
	for (int i = 1; i < n; i++)
	{
		if(s[i-1]=='A' && s[i]=='C')t[i]=t[i-1]+1;
		else t[i]=t[i-1];
	}
	while(q--)
	{
		int l,r;cin>>l>>r;
		cout<< t[r-1]-t[l-1]<<"\n";
	}
}