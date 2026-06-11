// Created by Nandu Vinodan
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define pi pair<int, int>
#define INF INT_MAX
#define _INF INT_MIN
#define TC 0 

using namespace std;
using ll = long long;

int n, k;
const int N = 55;
int v[N];
int dp[N][N][103];

int solve(int i, int j, int k) {
	if (k<=0 || i>j)
		return 0;
	 //db3(i, j, k);
	if (dp[i][j][k] != -1) return dp[i][j][k];

	// choose from left
	int res = v[i] + solve(i+1, j, k-1);
	// not choose from left
	res = max (res, solve(i+1, j, k-2));
	// choose from right
	res = max(res, v[j] + solve(i, j-1, k-1));
	// not choose from right 
	res = max(res, solve(i, j-1, k-2));
	// db3(i, j, k);
	// db1(res);
	return  dp[i][j][k] = res;
}
void testcase() {
    cin >> n >> k;
    rep (i, 0, n-1) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    if (TC)
        cin>>t;
    while(t--) {
        testcase();
    }
    return 0;
}