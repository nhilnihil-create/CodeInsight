#include<bits/stdc++.h>
using namespace std;
const int mx = 310;
double dp[mx+5][mx+5][mx+5];
int main()
{
	int n;
	cin >> n;
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(x == 1)
			cnt1++;
		else if(x == 2)
			cnt2++;
		else
			cnt3++;
	}
	for(int k=0;k<mx;k++){
		for(int j=0;j+k<mx;j++){
			for(int i=0;i+j+k<mx;i++){
				if(i == 0 && j == 0 && k == 0)
					continue;
				if(i+j+k > mx)
					continue;
				double p_a = 1.0*i/(i+j+k);
				double p_b = 1.0*j/(i+j+k);
				double p_c = 1.0*k/(i+j+k);
				double p_waste = 1.0 * n/(i+j+k);
				if(i)
					dp[i][j][k] += p_a*dp[i-1][j][k];
				if(j)
					dp[i][j][k] += p_b*dp[i+1][j-1][k];
				if(k)
					dp[i][j][k] += p_c*dp[i][j+1][k-1];
				dp[i][j][k] += p_waste;
			}
		}
	}
	printf("%.12lf\n",dp[cnt1][cnt2][cnt3]);
}