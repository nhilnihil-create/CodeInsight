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
vector<vector<double>> dp;
std::vector<double> p;
void solve(){

	dp[0][0] = (double)1 - p[0];
	dp[0][1] = p[0];
	for(int curr=1;curr<p.size();curr++){
		

	for(int i=0;i<=curr+1;i++){
		//dp[curr][i] = (double)0;
		if(i>0){
			dp[curr][i] += dp[curr-1][i-1]*p[curr];
		}
		dp[curr][i]+= dp[curr-1][i]*((double)1 - p[curr]);
	}

}

}
int main()
{
	
	ll n;
	cin>>n;
	dp = vector<vector<double>>(n,vector<double>(n+1,(double)0));
	 p = vector<double>(n);
	for(int i=0;i<n;i++)
		cin>>p[i];
	solve();

	double ans = 0;
	for(int i=0;i<=n;i++){

		if(i>n/2)
			ans+= dp[n-1][i];
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<=n;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	cout<<setprecision(10)<<ans<<endl;

	
}