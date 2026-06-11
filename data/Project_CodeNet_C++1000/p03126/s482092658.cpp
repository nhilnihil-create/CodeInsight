#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
	int a[N],flag[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>a[i];
			flag[a[i]]++;
		}
	}
	int ans=0;
	for(int i=1;i<=40;i++)
	{
		if(flag[i]==n)ans++;
	}
	cout<<ans;
	return 0;
}
