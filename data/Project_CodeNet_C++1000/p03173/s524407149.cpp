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

long long rec(vector<long long> a,vector<long long> prefix){
	int n = a.size();
	long long dp[n][n];

	for(int i = 0; i < n; i++){
		dp[i][i] = 0;
	}
	for(int len = 2; len <= n; len++){
		for(int i = 0; i + len -1< n; i++){
			int j = i + len -1;
			//dp[i][j] = 1000000000000;
			for(int k = i; k < j; k++){
				long long curr = 0;
				curr += dp[i][k];
				curr += dp[k+1][j];
				if(i > 0)curr += (prefix[k] - prefix[i-1]) + (prefix[j] - prefix[k]);
				else curr += prefix[j];
				if(k == i){
					dp[i][j] = curr;
				}
				else{
					dp[i][j] = min(dp[i][j], curr);
				}
			}
		}
	}
	return dp[0][n-1];
	// if(i == j){
	// 	return a[i];
	// }
	// int res = INT_MAX;
	// // int prefix[j- i + 1];
	// for(int k = i; k < j; k++){
	// 	int ans = 0;
	// 	ans += rec(a, i, k, prefix);
	// 	//dbg(ans);
	// 	ans += rec(a, k+1, j, prefix);
	// 	//dbg(ans);
	// 	if(i > 0)ans += (prefix[k] - prefix[i-1]) + (prefix[j] - prefix[k]);
	// 	else ans += (prefix[k]) + (prefix[j] - prefix[k]);
	// 	dbg(ans);
	// 	res = min(res, ans);
	// }
	// return res;

}

int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> prefix(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i > 0)prefix[i] = prefix[i-1] + a[i];
		else prefix[i] = a[i];
		//cout << prefix[i] << " ";
	}
	long long res = rec(a,prefix);
	cout << res << endl;
}