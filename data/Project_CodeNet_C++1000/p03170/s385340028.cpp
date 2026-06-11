#include<bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;
int main(){
	IOS;
	int n,k;
	cin>>n>>k;
	vector<int> stones(n);
	for(int i=0;i<n;i++)
	cin>>stones[i];
	sort(stones.begin(), stones.end());
	bool dp[100005];
	memset(dp, false, sizeof(dp));
	dp[0]=false;
	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			if(stones[j]<=i)
			{
			if(dp[i-stones[j]]==false)
			{
			dp[i]=true;
			break;
		}
			}
			else
			break;
		}
	}

if(dp[k])
cout<<"First";
else
cout<<"Second";
}