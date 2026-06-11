#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> s(N + 1);

    for(int i = 2; i <= N; i++) {
        int x = i;
        for(int j = 2; j * j <= x; j++) {
            if(x % j == 0) {
                while(x % j == 0) {
                    x /= j;
                    s[j]++;
                }
            }
        }
        if(x != 1) s[x]++;
    }

    vector<vector<int> > dp(N + 1, vector<int>(76));

    dp[1][1] = 1;

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < 76; j++)
            dp[i][j] = dp[i - 1][j];
        
        for(int j = 0; j < s[i]; j++) {
            for(int k = 1; k < 76; k++) {
                int x = k * (j + 2);
                if(x > 75) break;
                dp[i][x] += dp[i - 1][k];
            }
        }
    }

    cout << dp[N][75] << endl;
}