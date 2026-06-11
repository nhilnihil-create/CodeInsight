#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> pipii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
typedef priority_queue<pii> maxpq;
//const double PI = acos(-1);
const int mod = 1000000007;

// ----------------------DEBUG TEMPLATE--------------------------
void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
	cerr << '{';
	__print(x.first);
	cerr << ',';
	__print(x.second);
	cerr << '}';
}
template <typename T>
void __print(const T &x)
{
	int f = 0;
	cerr << '{';
	for (auto &i : x)
		cerr << (f++ ? "," : ""), __print(i);
	cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
	__print(t);
	if (sizeof...(v))
		cerr << ", ";
	_print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
	cerr << "[" << #x << "] = ["; \
	_print(x)
#else
#define debug(x...)
#endif
// ----------------------DEBUG TEMPLATE--------------------------



int bu(vi &arr,int n,int k){
	int dp[n+2][k+2];
	memset(dp,0,sizeof(dp));
	for(int i =0;i <=n;i++){
		dp[i][0]=1;
	}
	for(int i =1;i <=n;i++){
		
		for(int j =1;j<=k;j++){
			if(i==1){
				if(j<=arr[i]){
					dp[i][j]=1;
				}
				else{
					dp[i][j]=0;
				}
				continue;
			}
			if(j-arr[i]-1>=0){
				dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-arr[i]-1] + mod)%mod;
			}
			else{
				dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod ;
			}
			// for(int m=0; m<=arr[i] && m<=j;m++){
			// 	dp[i][j] += dp[i-1][j-m];
			// }
		}
	}
	// for(int i =k;i>=0;i--){
	// 	if(dp[n][i] != 0){
	// 		return dp[n][i];
	// 	}
	// }
	// fo(i,n+1){
	// 	fo(j,k+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return dp[n][k];


}



void solve(){
	int n,k;
	cin>>n>>k;
	vi arr(n+1);
	Fo(i,1,n+1) cin>>arr[i];
	cout<<bu(arr,n,k)<<endl;
	
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}


}