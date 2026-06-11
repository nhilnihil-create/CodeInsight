#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 * 1000 + 10;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;


int n;
double head[MAXN], dp[3007][3007]; //dp[coin index][number of coins];

void update(int coin_index)
{
    //cerr << "coin: " << coin_index << endl;

    //if(coin_index != 4){
        //dp[coin_index][coin_index / 2 - 1] += dp[coin_index - 2][coin_index / 2 - 3] * head[coin_index] * head[coin_index - 1];
    //}

    //dp[coin_index][coin_index / 2 - 1] += dp[coin_index - 2][coin_index / 2 - 1] * (1 - head[coin_index]) * (1 - head[coin_index - 1]);
    //dp[coin_index][coin_index / 2] += dp[coin_index - 2][coin_index / 2] * (1 - head[coin_index]) * (1 - head[coin_index - 1]);

    for(int i = 0; i < coin_index; i++){
        double add = 0.0;
        add += dp[coin_index - 2][i] * head[coin_index] * (1 - head[coin_index - 1]);
        add += dp[coin_index - 2][i] * head[coin_index - 1] * (1 - head[coin_index]);

        dp[coin_index][i + 1] += add;

        add = dp[coin_index - 2][i] * head[coin_index] * head[coin_index - 1];

        dp[coin_index][i + 2] += add;

        dp[coin_index][i] += dp[coin_index - 2][i] * (1 - head[coin_index]) * (1 - head[coin_index - 1]);

        //cerr << "i: " << i << ", i + 2: " << dp[coin_index][i + 2] << ", i + 1: " << dp[coin_index][i + 1] << endl;
    }

    dp[coin_index][coin_index + 2] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(15);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> head[i];

    dp[0][0] = 1 - head[0];
    dp[0][1] = head[0];

    dp[2][0] = dp[0][0] * (1 - head[2]) * (1 - head[1]);
    dp[2][1] += dp[0][1] * (1 - head[2]) * (1 - head[1]);
    dp[2][1] += dp[0][0] * (1 - head[2]) * (head[1]);
    dp[2][1] += dp[0][0] * (1 - head[1]) * (head[2]);
    dp[2][2] += dp[0][0] * head[2] * head[1];
    dp[2][2] += dp[0][1] * head[2] * (1 - head[1]);
    dp[2][2] += dp[0][1] * head[1] * (1 - head[2]);
    dp[2][3] += dp[0][1] * head[1] * head[2];


    for(int i = 4; i < n; i+=2){
        update(i);
    }

    double ans = 0.0;

    for(int i = n / 2 + 1; i <= n; i++){
        ans += dp[n - 1][i];
    }

    cout << ans << endl;

    return 0;
}

