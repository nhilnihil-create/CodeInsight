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
const int mod =1000000007;

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



void lcs(string a,string b){

	int x = a.length();
	int y = b.length();
	int dp[x+1][y+1];
	for(int i =0;i <=x;i++){
		dp[i][0]=0;
	}
	for(int i =0;i <=y;i++){
		dp[0][i]=0;
	}
	for(int i =1;i <=x;i++){
		for(int j =1;j <=y;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string res="";
	int i = x;int j = y;
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			res+=a[i-1];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	reverse(all(res));
	cout<<res<<endl;



}




int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a,b;
	cin>>a>>b;
	lcs(a,b);

}
	