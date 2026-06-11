#include<bits/stdc++.h>
using namespace std;

#define int     long long
#define inf 	1e18

int n;
vector<int> dp(1 << 16, -inf);
vector<vector<int> > v(18, vector<int> (18));
vector<int> group_val(1 << 16, -inf);

// calculates score that will be generated if we group all rabbits of mask(i.e all 1's) 
int cal_group_val(int mask) {
	int val = 0;

	if (group_val[mask] != -inf) {
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
	// cannot keep -1 because score can be negative as well
	if (dp[mask] != -inf) {
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
   //memset(dp, -1, sizeof dp);
   cout << solve((1 << n) - 1);
}
 
int32_t main()
{
    c_p_c();
    return 0;
}