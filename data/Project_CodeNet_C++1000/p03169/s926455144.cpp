#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define ff first
#define ss second
 
#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif
 
const int inf = 2e18;
const int mod = 1e9 + 7;
int n;
double dp[301][301][301];

double dfs(int a, int b, int c){
	// cout<<a<<b<<c<<endl;
	if(dp[a][b][c]!=-1) return dp[a][b][c];

	dp[a][b][c] = 0;
	if(c>0) dp[a][b][c]+=(dfs(a,b+1,c-1)+(double)n/(a+b+c))*((double)c/(a+b+c));
	if(b>0) dp[a][b][c]+=(dfs(a+1,b-1,c)+(double)n/(a+b+c))*((double)b/(a+b+c));
	if(a>0) dp[a][b][c]+=(dfs(a-1,b,c)+(double)n/(a+b+c))*((double)a/(a+b+c));

	return dp[a][b][c];

}

signed main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#endif
 
	cin>>n;
	vector<int> arr = {0, 0, 0};
	for(int i=0; i<n; i++){
		int x; cin>>x;
		arr[x-1]++;
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			for(int k=0; k<=n; k++){
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][0][0] = 0;

	cout<<setprecision(11)<<dfs(arr[0], arr[1], arr[2])<<endl;

	return 0;
}