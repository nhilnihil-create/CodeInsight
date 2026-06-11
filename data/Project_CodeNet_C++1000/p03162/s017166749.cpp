#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i] >> c[i];
	}
	int DP[n][3];
	tie(DP[n-1][0], DP[n-1][1], DP[n-1][2]) = tie(a[n-1], b[n-1], c[n-1]);
	for(int i = n-2; i >= 0; --i){
		DP[i][0] = a[i] + max(DP[i+1][1], DP[i+1][2]);
		DP[i][1] = b[i] + max(DP[i+1][0], DP[i+1][2]);
		DP[i][2] = c[i] + max(DP[i+1][0], DP[i+1][1]);
	}
	cout << max({DP[0][0], DP[0][1], DP[0][2]}) << endl;
}