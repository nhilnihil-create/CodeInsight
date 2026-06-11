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

vector<int> *adj;
int V, E;

void addEdge(int x, int y)
{
	adj[x].push_back(y);
}
int dp[100005];
int giveLongestPath(int n){
	if(adj[n].size()==0){
		return 0;
	}
	if(dp[n]>-1){
		return dp[n];
	}
	dp[n]=0;
	for(int nbr : adj[n]){
		dp[n] =  max(1 + giveLongestPath(nbr),dp[n]);
	}
	return dp[n];
}

void cover(){
	int ans=0;
	Fo(i,1,V+1){
		ans = max(ans,giveLongestPath(i));
	}
	cout<<ans<<endl;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	adj = new vector<int>[V+1];
	for(int i =0;i <E;i++){
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	memset(dp,-1,sizeof(dp));
	cover();




}
