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
	cin >>n;
	cout << fixed << setprecision(15);
	vector<double> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	double dp[n+1][n+1];
	if(n == 0){
		cout << 0 << endl;
	}
	// dp[i] is the probabilty  upto i'th index
	dp[0][0] = 1;
	for(int heads = 1; heads <= n; heads++){
		dp[0][heads] = 0;
	}
	for(int i = 1; i <= n; i++){
		dp[i][0] = dp[i-1][0] * (1 - p[i-1]);
	}
	for(int i = 1; i <= n; i++){
		for(int heads = 1; heads <= i; heads++){
			dp[i][heads] = dp[i-1][heads-1] * (p[i-1]) + dp[i-1][heads] * (1 - p[i-1]);
		}
	}
	double ans = 0;
	// for(int i = 1; i <= n; i++){
	// 	for(int heads = 0; heads <= i; heads++){
	// 		cout << dp[i][heads] << " ";
	// 	}cout << endl;
	// }
	for(int k = (n+1)/2; k <= n; k++){
		ans += dp[n][k];
	}
	cout << ans << endl;
}