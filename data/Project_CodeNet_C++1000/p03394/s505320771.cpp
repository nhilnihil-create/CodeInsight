#include<bits/stdc++.h>
using namespace std;
const int maxn = 30001;
vector<int>ans; 
int vis[maxn];
int main()
{
	int n;
	cin>>n;
	int cnt = 0;
	int sum = 0;
	for(int i=1;i<=maxn;i++)
	{
		if(cnt==n-1)
			break;
		if(i%2==0||i%3==0)
		{
			ans.push_back(i);
			cnt++;
			sum+=i;
			vis[i] = 1;
		}
	}
	for(int i=1;i<=maxn;i++)
	{
		if(!vis[i]&&__gcd(sum,i)!=1&&(i+sum)%2==0&&(i+sum)%3==0)
		{
			ans.push_back(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}