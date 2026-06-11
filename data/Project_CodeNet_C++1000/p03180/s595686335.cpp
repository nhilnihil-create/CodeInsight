#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define forn(i,n) for(int i = 0; i< n;++i)
ll MOD = 1e9;
ll INF = 1e17 + 9;

//currMask is new no. of total used rabbits, group set biit denotes used rabbits in this group
void rec(int mask,int currMask,int i,vector<int>& free,vector<ll>& pre,vector<ll>& dp, int group){
	if(i == (int)free.size()){
		dp[currMask] = max(dp[currMask], dp[mask] + pre[group]);
		return;
	}
	rec(mask,currMask,i+1,free,pre,dp,group);
	rec(mask, currMask | 1 << free[i], i+1, free,pre,dp,group | (1 << free[i]));
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
		
	vector<vector<int>> A(n,vector<int> (n,0));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> A[i][j];
		}
	}
	
	//map<vector<int>,ll> dp;
	
	//cout <<  maxScore(0,0,0,(1<<n) - 1,n,A,dp) << endl;
	vector<ll> pre(1 << n, 0);
	vector<int> free;
	vector<ll> dp(1 << n, 0);  // dp[mask] -> max score to group rabbits with set bits
	//dp[mask]  0, init as it is possible to make each rabbit in one group, so atleast we get 0 score
	for(int mask = 0; mask < (1 << n); ++mask){
		
		for(int bit = 0; bit < n; ++bit){
			if((mask >> bit) & 1){
				for(int j = bit + 1; j < n; ++j){
					if((mask >> j) & 1){
						pre[mask] += A[bit][j];
					}
				}
			}
		}
	}
	// O(2^n * 2^n)
	for(int mask = 0; mask < (1 << n) ; ++mask){
		
		for(int bit = 0; bit < n; ++bit){
			if(!((mask >> bit) & 1)){
				free.push_back(bit);
			}
		}
		
		//dp[mask] -> score of using set rabbits for grouping
		
		rec(mask,mask,0,free,pre,dp,0);
		
		free.clear();
		
		
	}
	
	cout << dp[(1<<n) - 1] <<  endl;
		
}


