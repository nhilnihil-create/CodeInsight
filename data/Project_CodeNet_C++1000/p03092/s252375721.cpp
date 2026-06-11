#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, p[5005], A, B, dp[5005][5005];
ll pos[5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A >> B;
	for (int i = 1; i <= N; ++i){
		cin >> p[i];
	}
	for (int i = 1; i <= N; ++i){
		pos[p[i]] = i;
	} 
	for (int i = 1; i <= N+1; ++i){
		if (i < pos[1]) dp[1][i] = B;
		else if (i > pos[1]) dp[1][i] = A;
		else dp[1][i] = 0;
	} 
	for (int i = 2; i <= N; ++i){
		deque<pair<ll,int> > f;
		for (int j = 1; j <= N+1; ++j){
			while (!f.empty() && f.back().first > dp[i-1][j]){
				f.pop_back();
			}
			f.push_back(make_pair(dp[i-1][j],j));
			if (j == pos[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = 1e16;
			if (!f.empty()){
				if (j > pos[i]) dp[i][j] = min(dp[i][j],A+f.front().first);
				else if (j < pos[i]) dp[i][j] = min(dp[i][j],B+f.front().first);
				else dp[i][j] = min(dp[i][j],f.front().first);
			}
			
		}
	} 
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= N+1; ++j){
			//cout << dp[i][j] << ' ';
		}
		//cout << '\n';
	} 
	ll M = 1e16;
	for (int i = 1; i <= N+1; ++i){
		M = min(M,dp[N][i]);
	}
	cout << M << '\n';
}