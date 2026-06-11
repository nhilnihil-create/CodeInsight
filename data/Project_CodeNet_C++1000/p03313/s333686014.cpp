#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 18;
int dp[N + 1][1 << N][2];

void add(int a[2], int b[2]) {
	for (int i = 0; i < 2; i++) {
		if (b[i] > a[0]) {
			a[1] = a[0];
			a[0] = b[i];
		}
		else if (b[i] > a[1]) {
			a[1] = b[i];
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

   	memset(dp, -1, sizeof(dp));

    for (int i = 0; i < (1 << n); i++) {
    	cin >> dp[0][i][0];
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < (1 << n); j++) {
    		dp[i + 1][j][0] = dp[i][j][0];
    		dp[i + 1][j][1] = dp[i][j][1];
    		if ((j >> i) & 1)
    			add(dp[i + 1][j], dp[i][j ^ (1 << i)]);
    	}
    }

    int mx = 0;
    for (int i = 1; i < (1 << n); i++) {
    	mx = max(mx, dp[n][i][0] + dp[n][i][1]);
    	cout << mx << "\n";
    }

    return 0;   
}   