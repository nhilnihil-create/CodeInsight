#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void sb()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
vector<vector<int>> dp;
ll n;
ll k;
vector<int> a;
int solve(int left,int chance){

	//cout<<" count "<<endl;
	if(dp[chance][left]!=-1)
		return dp[chance][left];

	if(left==0)
		return dp[chance][left] = !chance;
	//cout<<left<<" : "<<chance<<endl;
	bool temp = 0;
 
	for(int i=0;i<n;i++){
		if(left>=a[i]){
			//cout<<left<<" "<<a[i]<<endl;
		temp|= (solve(left-a[i],!chance)==chance);
	}
	}
	int ret;
	if(temp==0)
		ret = !chance;
	else ret = chance;
	return dp[chance][left] = ret;
}
int main()
{
	
	
	cin>>n;
	
	cin>>k;
	 a = vector<int>(n);
	dp = vector<vector<int>>(2,vector<int>(k+1));

	for(int i=0;i<2;i++)
		for(int j=0;j<=k;j++)
			dp[i][j] = -1;
		
	
	for(int i=0;i<n;i++)
		cin>>a[i];

	bool ans;
	ans = solve(k,0);
	//  for(int i=0;i<2;i++){
	// 	for(int j=0;j<=k;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	if(ans==0)
		cout<<"First";
	else cout<<"Second";
	
}