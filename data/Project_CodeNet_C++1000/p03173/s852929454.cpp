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
#define MAX 1e18

int n;
int a[401];
int dp[401][401];

int csum(int s,int e){
	int sum=0;
	loop(i,s,e){
		sum+=a[i];
	}
	return sum;
}


int solve(int i,int j){
	if(i>=j){
		return 0;
	}

	if(dp[i][j]!=-1) return dp[i][j];

	int mini=MAX;
	for(int k=i;k<=j-1;k++){
		int temp = solve(i,k)+solve(k+1,j)+csum(i,k)+csum(k+1,j);
		mini=min(mini,temp);
	}

	return dp[i][j]=mini;
}

signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin >> n;
	for0(i,n)cin>>a[i];

	memset(dp,-1,sizeof(dp));

	cout<<solve(0,n-1);

	return 0;
}