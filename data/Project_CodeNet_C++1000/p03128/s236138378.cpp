#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
vector<int> c = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
	int N, M;
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; i++){
		cin >> A[i];
	}
	set<int> st;
	for (int i = 0; i < M; i++){
		st.insert(A[i]);
	}
	vector<vector<int>> num(8);
	for (int i = 0; i < M; i++){
		num[c[A[i]]].push_back(A[i]);
	}
	for (int i = 0; i < 8; i++){
		sort(num[i].begin(), num[i].end());
		reverse(num[i].begin(), num[i].end());
	}
	int mn = -1;
	for (int i = 0; i < 8; i++){
		if (!num[i].empty()){
			mn = i;
			break;
		}
	}
	string ans = "";
	while (N >= 36){
		N -= mn;
		ans += '0' + num[mn][0];
	}
	//DP
	vector<vector<bool>> dp(20, vector<bool>(36, false));
	dp[0][0] = true;
	for (int i = 0; i < 19; i++){
		for (int j = 0; j < 36; j++){
			if (dp[i][j]){
				for (int k = 0; k < 8; k++){
					if (!num[k].empty() && j + k < 36){
						dp[i + 1][j + k] = true;
					}
				}
			}
		}
	}
	int L = 0;
	for (int i = 0; i < 20; i++){
		if (dp[i][N]){
			L = i;
		}
	}
	while (L > 0){
		for (int i = 9; i >= 1; i--){
			if (st.count(i) && N >= c[i]){
				if (dp[L - 1][N - c[i]]){
					L--;
					N -= c[i];
					ans += '0' + i;
					break;
				}
			}
		}
	}
	sort(ans.rbegin(), ans.rend());
	cout << ans << endl;
}