/*input
FFFFFFF
7 0
*/
#include<bits/stdc++.h>
using namespace std;
const int N=8001;
const int mod=1e9 + 7;
#define int long long
const int inf=1e18;
#define pii pair<int, int>
#define f first
#define s second 
#define mp make_pair
set<int> dp[4001];string st;int t[2];
vector<int> arr[2];
bool solve(int ind, int start)
{
	int sum=0;
	for(auto j:arr[ind]) sum+=j;
	for(int i=0;i<4001;i++) dp[i].clear();
	dp[0].insert(start);
	for(int i=0;i<arr[ind].size();i++)
	{
		sum-=arr[ind][i];//cout<<i<<" : ";
		for(auto j:dp[i])
		{
//			cout<<j<<" ";
			if((t[ind]>0&&j + arr[ind][i] - sum <=t[ind])||(t[ind]<=0&&j + arr[ind][i] + sum >=t[ind])) dp[i+1].insert(j+arr[ind][i]);
			if((t[ind]>0&&j - arr[ind][i] - sum <=t[ind])||(t[ind]<=0&&j - arr[ind][i] + sum >=t[ind])) dp[i+1].insert(j-arr[ind][i]);
		}
	}
	return dp[arr[ind].size()].count(t[ind]);
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>st>>t[0]>>t[1];int cur=0, ind=0;
	for(auto i:st)
	{
		if(i=='F') cur++;
		else
		{
			arr[ind].push_back(cur);cur=0;ind^=1;
		}
	}
	if(cur!=0) arr[ind].push_back(cur);
	int val=arr[0][0];arr[0].erase(arr[0].begin());
	if(solve(0, val)&&solve(1, 0)) cout<<"Yes";
	else cout<<"No";
}