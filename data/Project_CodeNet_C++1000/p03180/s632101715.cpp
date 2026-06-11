#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, dp[100000];
vector<vector<int> > v(18, vector<int> (18));
vector<int> group_val(1 << 17, -1);

int cal_group_val(int mask) {
	int val = 0;

	if (group_val[mask] != -1) {
		return group_val[mask];
	}

	for (int i = 0; i < 17; i++) {
		for (int j = i + 1; j < 17; j++) {
			if ((mask >> i) & 1 && (mask >> j) & 1) {
				val += v[i][j];
			}
		}
	}
	
	group_val[mask] = val;
	return val;
}
 
int solve(int mask) {
	if (mask == 0) {
		return 0;
	}

	if (dp[mask] != -1) {
		return dp[mask];
	}

	// generate all submask of mask
	for (int submask = mask; submask != 0; submask = (submask - 1) & mask) {
		dp[mask] = max(dp[mask], cal_group_val(submask) + solve (mask ^ submask)); // mask ^ submask = gives all mask of values that are not included in submask
	}

	return dp[mask];
}

void c_p_c()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
   #ifndef ONLINE_JUDGE
	freopen("/home/abhinav/c++ codes/input output c++/input.txt", "r", stdin);
	freopen("/home/abhinav/c++ codes/input output c++/output.txt", "w", stdout);
   #endif
   
   cin >> n;

   for (int i = 0; i < n; i++) {
   		for (int j = 0; j < n; j++) {
   			cin >> v[i][j];
   		}
   }
   memset(dp, -1, sizeof dp);
   cout << solve((1 << n) - 1);
}
 
int32_t main()
{
    c_p_c();
    return 0;
}