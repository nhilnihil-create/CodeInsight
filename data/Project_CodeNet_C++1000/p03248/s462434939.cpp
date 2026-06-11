#include <bits/stdc++.h>
#define int long long
#define iris 998244353
using namespace std;

int arr[100010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i;
	string s;
	cin>>s;
	n=s.size();
	s='0'+s;
	
	if(s[1]=='0' || s[n]=='1')
	{
		cout<<"-1\n";
		return 0;
	}
	for(i=n-1;i;i--)
	{
		if(s[i]!=s[n-i])
		{
			cout<<"-1\n";
			return 0;
		}
		if(!arr[i])
		{
			arr[i]=i+1;
		}
		if(s[i]=='0')
		{
			arr[i-1]=arr[i];
		}
	}
	
	for(i=1;i<n;i++)
	{
		cout<<i<<' '<<arr[i]<<'\n';
	}
	
	return 0;
}