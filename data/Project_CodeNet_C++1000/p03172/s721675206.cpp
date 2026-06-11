#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) <<" , "<< #z <<": "<<(z)<<endl; }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
#define mod (int)(1e9 + 7) 

using namespace std;
long long dp[105][100005];

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i <= n; i++){
		dp[i][0] = 1;
	}
	vector<long long> prefix_sum(k+1);
	for(int j = 0; j <= k; j++){
		if(j <= a[n-1])dp[n-1][j] = 1;
		else dp[n-1][j] = 0;
		if(j > 0)prefix_sum[j] = prefix_sum[j-1] + dp[n-1][j];
		else prefix_sum[j] = dp[n-1][j];
		if(prefix_sum[j] > mod){
			prefix_sum[j] -= mod;
		}
	}

	for(int i = n-2; i >= 0; i--){
		vector<long long> new_prefix_sum(k+1);
		for(int j = 0; j <= k; j++){
			dp[i][j] = 0;
			if(j >= a[i] + 1)dp[i][j] += (prefix_sum[j] - prefix_sum[j - a[i] - 1] + mod)%mod;
			else dp[i][j] = prefix_sum[j];
			if(dp[i][j] > mod) dp[i][j] -= mod;
			if(j > 0)new_prefix_sum[j] = new_prefix_sum[j-1] + dp[i][j];
			else new_prefix_sum[j] = dp[i][j];
			if(new_prefix_sum[j] > mod){
				new_prefix_sum[j] -= mod;
			}
		}
		prefix_sum = new_prefix_sum;
	}
	cout << dp[0][k]%mod <<endl;
}