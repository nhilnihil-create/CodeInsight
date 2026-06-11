#include <iostream>
#include <vector>
#include <map>
using namespace std;
long long MOD = 1000000007;
int main(){
	int N;
	cin >> N;
	vector<int> C(N + 1);
	for (int i = 1; i <= N; i++){
		cin >> C[i];
	}
	map<int, int> mp;
	vector<int> prev(N + 1);
	for (int i = 1; i <= N; i++){
		prev[i] = mp[C[i]];
		mp[C[i]] = i;
	}
	vector<long long> dp(N + 1);
	dp[0] = 1;
	for (int i = 1; i <= N; i++){
		if (prev[i] == i - 1 || prev[i] == 0){
			dp[i] = dp[i - 1];
		} else {
			dp[i] = dp[i - 1] + dp[prev[i]];
			dp[i] %= MOD;
		}
	}
	cout << dp[N] << endl;
}