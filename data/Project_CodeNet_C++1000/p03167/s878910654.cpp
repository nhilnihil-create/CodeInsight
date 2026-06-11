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
                                         
#define M 1000000007
ll h,w;
int main() {
	FAST
	cin>>h>>w;
	ll dp[h][w] = {0};
    char grid[h][w];  
	rep(i,h)
	{
		rep(j,w)
		{
			cin>>grid[i][j];
		}
	}
	dp[0][0] = 1;
	rep(i,h)
	{
		rep(j,w)
		{
			if(grid[i][j] == '#')
			{
				dp[i][j] = 0;
			}
			else{
				if(i>0 && j>0)dp[i][j] = (dp[i][j-1]%M + dp[i-1][j]%M)%M;
				else if(i==0 && j!=0)dp[i][j] = dp[i][j-1];
				else if(j==0 && i!=0)dp[i][j] = dp[i-1][j];
			}
			//deb(dp[i][j]);
		}
	}
	cout<<dp[h-1][w-1]<<endl;
	
	
}
