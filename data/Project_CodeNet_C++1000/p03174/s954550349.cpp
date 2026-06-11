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

int main(){
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			 cin >> a[i][j];
		}
	}
	vector<int> dp(1 << n);
	dp[0] = 1;
	for(int mask = 0; mask < (1 << n); mask++){
		int men = __builtin_popcount(mask);
		for(int women = 0; women < n; women++){
			if(a[men][women] && !(mask &(1 << women))){
				int new_mask = mask | (1 << women);
				dp[new_mask] += dp[mask];
				if(dp[new_mask] > mod){
					dp[new_mask] -= mod;
				}
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;
}
