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
#define N 3000
vector<double>heads(N),tails(N);
// double heads[N];
// double tails[N];
double dp[N][N];
double solve(int n){
	memset(dp,0.0,sizeof(dp));
	
	dp[0][0]=1.0;
	for(int i=1;i <=n;i++){
		dp[0][i]=dp[0][i-1]*tails[i];
	}
	for(int i =1;i <=n;i++){
		dp[i][i]=dp[i-1][i-1]*heads[i];
	}
	// debug(heads,tails);
	

	for(int col=2;col<=n;col++){
		int row = 1;
		while(row<col){
			dp[row][col] = dp[row-1][col-1]*heads[col] + dp[row][col-1]*tails[col];
			row++;
		}
	}
	// fo(i,n+1){
	// 	fo(j,n+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	double ans=0;
	for(int i = ceil(n/2.0);i<=n;i++){
		ans+=dp[i][n];
	}
	return ans;	

}



int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	Fo(i,1,n+1){
		cin>>heads[i];
		tails[i] = 1-heads[i];
	}
	cout<<fixed<<setprecision(10)<<solve(n)<<endl;

}