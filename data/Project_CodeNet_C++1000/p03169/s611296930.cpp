#include<bits/stdc++.h>
using namespace std;

double dp[310][310][310];
int N;

double solve(int i, int j, int k){
	if(i+j+k == 0) return 0.0;
	if(dp[i][j][k] > -0.5) return dp[i][j][k];
	double p = (double)N /(i+j+k);
	double ret = 0;
	if(i){
		ret += (solve(i-1, j, k)+p)*i/(i+j+k);
	}
	if(j){
		ret += (solve(i+1, j-1, k)+p)*j/(i+j+k);
	}
	if(k){
		ret += (solve(i, j+1, k-1)+p)*k/(i+j+k);
	}
	
	dp[i][j][k] = ret;
	return ret;
}

int main(){
	int n;
	cin >> n;
	N = n;
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 1) a++;
		else if(x == 2) b++;
		else if(x == 3) c++;
	}

	for(int i = n; i >= 0; i--){
		for(int j = n; j >= 0; j--){
			for(int k = n; k >= 0; k--){
				dp[i][j][k] = -1;
			}
		}
	}
	
	double ans = solve(a, b, c);
	cout << fixed << setprecision(10) << ans << endl;
	
}