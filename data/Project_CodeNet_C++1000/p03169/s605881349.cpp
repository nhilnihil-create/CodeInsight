#include "bits/stdc++.h"
using namespace std;
int n, c1, c2, c3, x; 
long double dp[303][303][303];
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> x;
		if (x==1) c1++;
		else if (x==2) c2++;
		else c3++;
	}
	for (int k=0; k<=c3; k++)
		for (int j=0; j<=(c3+c2-k); j++)
			for (int i=0; i<=(n-j-k); i++){
				if(i+j+k==0) continue; 
				dp[i][j][k] = ((long double)(n))/(i+j+k);
				if(i) dp[i][j][k] += (((long double)(i))/(i+j+k)) * dp[i-1][j][k];
				if(j) dp[i][j][k] += (((long double)(j))/(i+j+k)) * dp[i+1][j-1][k];
				if(k) dp[i][j][k] += (((long double)(k))/(i+j+k)) * dp[i][j+1][k-1];
		//		cout << i << " " << j << " " << k << "   " << dp[i][j][k] << endl;
			}
	cout << setprecision(12) << dp[c1][c2][c3];
return 0;
}