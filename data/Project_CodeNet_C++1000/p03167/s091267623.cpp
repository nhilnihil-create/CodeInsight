#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 * 1000 + 10;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;

long long dp[3005][3005];
bool sch[3005][3005];

int h, w;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cout << fixed << setprecision(10);

    cin >> h >> w;

    long long ans = 0, mod = 1000 * 1000 * 1000 + 7;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char r;
            cin >> r;
            if(r == '.') sch[i][j] = true;
        }
    }

    for(int i = 0; i < h; i++){
        if(!sch[i][0]) break;
        dp[i][0] = 1;
    }
    for(int i = 0; i < w; i++) {
        if(!sch[0][i]) break;
        dp[0][i] = 1;
    }

    for(int i = 1; i < w + h; i++){
        for(int j = 1; j < min(h, i); j++){
            int k = i - j;
            if(k > w) continue;

            if(sch[j - 1][k]) dp[j][k] += dp[j - 1][k];
            if(sch[j][k - 1]) dp[j][k] += dp[j][k - 1];

            dp[j][k] %= mod;
            //cerr << "j: " << j << " k: " << k << ' ' << dp[j][k] << endl;
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}

