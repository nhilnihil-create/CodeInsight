#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int N;
    cin >> N;
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == 1) one++;
        if (a == 2) two++;
        if (a == 3) three++;
    }
    vector<vector<vector<double>>> dp(N+1, vector<vector<double>>(N+1, vector<double>(N+1, 0)));
    for (int rem = 1; rem <= N*3; rem++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; i+j*2 <= rem && j <= N; j++) {
                if ((rem-i-j*2)%3 != 0) continue;
                int k = (rem-i-j*2)/3;
                if (k < 0 || k > N) continue;
                if (i+j+k > N) continue;
                double roll = (double)N / (i+j+k);
                if (i > 0) dp[i][j][k] += (dp[i-1][j][k]+roll)*(double)i/(i+j+k);
                if (j > 0) dp[i][j][k] += (dp[i+1][j-1][k]+roll)*(double)j/(i+j+k);
                if (k > 0) dp[i][j][k] += (dp[i][j+1][k-1]+roll)*(double)k/(i+j+k);
            }
        }
    }
    cout << setprecision(15) << dp[one][two][three] << endl;
    return 0;
}