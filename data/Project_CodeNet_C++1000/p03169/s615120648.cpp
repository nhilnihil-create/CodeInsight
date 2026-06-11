#include<bits/stdc++.h>

using namespace std;

int a[302] = {};
double dp[302][302][302] = {};
double p[302][302][302] = {};
double add[302][302][302] = {};

int main() {
	
	int i,j,k;
	int N;
	
	cin >> N;
	for( i=1; i<=N; i++) {
		cin >> a[i];
	}
	
	int cnt[4] = {};
	for( i=1; i<=N; i++) {
		cnt[ a[i] ]++;
	}
	
	p[ cnt[1] ][ cnt[2] ][ cnt[3] ] = 1;
	for( i= N; i>=0; i--) {
		for( j= N; j>=0; j--) {
			for( k= N; k>=0; k--) {
				if( k > 0)
					p[k-1][j][i] += p[k][j][i] * (double) k / (k+j+i);
				if( j > 0)
					p[k+1][j-1][i] += p[k][j][i] * (double) j / (k+j+i);
				if( i > 0)
					p[k][j+1][i-1] += p[k][j][i] * (double) i / (k+j+i);
			}
		}
	}
	
	for( i= N; i>=0; i--) {
		for( j= N; j>=0; j--) {
			for( k= N; k>=0; k--) {
				double pt = 0;
				dp[k][j][i] += ( dp[k+1][j][i] + (double) N / (k+1+j+i) ) * p[k+1][j][i] * (k+1) / (k+1+j+i);
				pt += p[k+1][j][i] * (k+1) / (k+1+j+i);
				if( k > 0) {
					dp[k][j][i] += ( dp[k-1][j+1][i] + (double) N / (k+j+i) ) * p[k-1][j+1][i] * (j+1) / (k+j+i);
					pt += p[k-1][j+1][i] * (j+1) / (k+j+i);
				}
				if( j > 0) {
					dp[k][j][i] += ( dp[k][j-1][i+1] + (double) N / (k+j+i) ) * p[k][j-1][i+1] * (i+1) / (k+j+i);
					pt += p[k][j-1][i+1] * (i+1) / (k+j+i);
				}
				
				if( pt == 0)
					continue;
				dp[k][j][i] /= pt;
//				dp[k][j][i] += (double) N / (k+j+i);
			}
		}
	}
	double ans = dp[0][0][0];
//	while(1) {
//		int q1, q2, q3, q4;
//		scanf("%d %d %d", &q1, &q2, &q3);
//		printf(">>> p = %.15f, dp = %.15f\n", p[q1][q2][q3], dp[q1][q2][q3]);
//	}
	
	printf("%.15f\n", ans);
	
	return 0;
} 