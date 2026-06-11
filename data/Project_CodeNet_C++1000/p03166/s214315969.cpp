//Author : Nishit Patel
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef double db;
typedef long long ll;
#define pb push_back
#define FAST cin.sync_with_stdio(0); cin.tie(0);
#define rep(i, n)      for(int i = 0; i < (n); ++i)
#define arep(i, a, n)  for(int i = a; i <= (n); ++i)
#define drep(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x)     for(auto& a : x)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef map<ll, ll> ml;
typedef unordered_map<ll, ll> hash;
#define deb_1(A)                     {cerr << "[" << #A << "] : " << A << endl;}
#define deb_2(A,B)                   {cerr << "[" << #A << "] : " << A << endl<< "[" << #B << "] : " << B << endl;}
#define deb_3(A,B,C)                 {cerr << "[" << #A << "] : " << A << endl<< "[" << #B << "] : " << B << endl\
									   << "[" << #C << "] : " << C << endl;}
#define deb_4(A,B,C,D)               {cerr << "[" << #A << "] : " << A << endl<< "[" << #B << "] : " << B << endl\
									   << "[" << #C << "] : " << C << endl<< "[" << #D << "] : " << D << endl;}
#define deb_X(x,A,B,C,D,FUNC, ...)  FUNC  
#define deb(...)                    deb_X(,##__VA_ARGS__,\
                                          deb_4(__VA_ARGS__),\
                                          deb_3(__VA_ARGS__),\
                                          deb_2(__VA_ARGS__),\
                                          deb_1(__VA_ARGS__),\
                                         )
                                         
                                         
#define L 1000005
bitset<L> bt;
ll memo[1000005];
ll dfs(ll curr,vector<vector<ll>> &v,ll depth)
{
	 if(bt[curr] == 1)
	 {
		 return memo[curr]+1;
	 }
	 bt[curr] = 1;
	 ll logest_depth =0;
	 for(int i=0;i<v[curr].size();i++)
	 {
		 if(memo[v[curr][i]] == 0)
		 {
			 logest_depth = max(logest_depth,dfs(v[curr][i],v,depth));
		 }
		 else{
			 logest_depth = max(logest_depth,memo[v[curr][i]]+1);
		 }
	 }
	 memo[curr] = logest_depth;
	 return 1+logest_depth;
}
int main() {
	FAST
	ll n,m,x,y;
	cin>>n>>m;
	vector<vector<ll>> v(n+1);
	rep(i,m)
	{
		cin>>x>>y;
		v[x].pb(y);
	}
	ll depth = INT_MIN;
	arep(i,1,n)
	{
		if(bt[i] == 0)
		{
			depth= max(depth,dfs(i,v,0));
		}
			
	}
	cout<<depth-1<<endl;
}
