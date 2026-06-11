#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

int solve(int x)
{
	vector<bool> ans(x+1);
	ans[1]=1;
	int v;
	for(int b=2;b<=x;b++)
	{
		v = b*b;
		while(v<=x)
		{
			ans[v]=1;
			v*=b;
		}
	}
	for(int i=x;i>=1;i--)
	{
		if(ans[i])
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}

int x,ans=0;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
	cin>>x;
	solve(x);	
}
	