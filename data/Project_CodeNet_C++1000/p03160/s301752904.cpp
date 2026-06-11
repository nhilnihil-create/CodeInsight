#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <climits>

#define el '\n'
typedef long long ll;
using namespace std;

void sol(){
	int n;
	cin >>n;
	vector<int> h(n);
	for (int &i: h) cin >>i;
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	dp[1] = abs(h[0] - h[1]);
	for (int i = 2; i < n; i++){
		dp[i] = min({dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]), dp[i]});
	}
	cout << dp[n - 1]<<el;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t= 1;
	while(t--){
	//	cout << t<<el;
		sol();
	}
}