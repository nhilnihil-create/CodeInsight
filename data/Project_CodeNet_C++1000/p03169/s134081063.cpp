#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int>cnt(4);


int main() {
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
	    int a;
	    cin >> a;
	    cnt[a]++;
	}
	double dp[301][301][301];
	dp[0][0][0] = 0;
	int cnt1 = cnt[1] + cnt[2] + cnt[3];
	int cnt2 = cnt[2] + cnt[3];
	int cnt3 = cnt[3];
	double t = 0;
	for(int k = 0; k <= cnt3; ++k)
	{
	    for(int j = 0; j <= cnt2 - k; ++j)
	    {
	        for(int i = 0; i <= cnt1-j-k; ++i)
	        {
	            t = i+j+k;
	            if(t > 0)
	                dp[i][j][k] = n/double(t);
	            if(k > 0)
	                dp[i][j][k] += (double(k)/t)*dp[i][j+1][k-1];
                if(j > 0)
                    dp[i][j][k] += (double(j)/t)*dp[i+1][j-1][k];
                if(i > 0)
                    dp[i][j][k] += (double(i)/t)*dp[i-1][j][k];
	        }
	    }
	}
	cout << fixed << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]];
	return 0;
}
