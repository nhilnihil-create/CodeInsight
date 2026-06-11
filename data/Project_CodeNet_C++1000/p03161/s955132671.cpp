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
	int n,k;
	cin >>n>>k;
	vector<int> h(n);
	for (int &i: h) cin >>i;
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i < n; i++){
		for (int j = 1; j <= min(k, i); j++)
		dp[i] = min(dp[i - j] + abs(h[i] - h[i - j]), dp[i]);
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