#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define dd double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl '\n'

int n;
int a[101];
vector<vector<int>>dp(101,vector<int>(100005,-1));

int candies(int ind,int left){
	if(left==0) return 1;
	if(ind==0||left<0) return 0;

	int &ans=dp[ind][left];
	if(ans!=-1)return ans;

	ans=candies(ind,left-1);
	ans=(ans+candies(ind-1,left))%mod;
	ans=(ans-candies(ind-1,left-a[ind-1]-1)+mod)%mod;
	return ans;
}


signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	int k;
	cin>>n>>k;
	for0(i,n)cin>>a[i];

	cout<<candies(n,k);

	return 0;
}