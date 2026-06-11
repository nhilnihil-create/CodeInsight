#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 * 1000 + 10;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;

long long mod = 1000 * 1000 * 1000 + 7;
int n, k;
int candy[MAXN];

long long dp[200][MAXN]; // dp [number of students][remained candies]
long long sum[MAXN];

void update(int students)
{
    //cerr << "students " << students << endl;

    sum[0] = dp[students - 1][0];

    for(int i = 1; i <= k; i++) sum[i] = (sum[i - 1] + dp[students - 1][i]) % mod;

    dp[students][0] = sum[candy[students - 1]] % mod;
    //cerr << "i " << 0 << ' ' << dp[students][0] << endl;

    for(int i = 1; i <= k; i++){
        dp[students][i] = (mod + sum[min(candy[students - 1] + i, k) ] - sum[i - 1]) % mod;
        //cerr << "i " << i << ' ' << dp[students][i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cout << fixed << setprecision(15);


    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> candy[i];

    dp[0][k] = 1;

    for(int i = k - candy[0]; i <= k; i++) dp[1][i] = 1;

    for(int i = 2; i <= n; i++) update(i);

    cout << dp[n][0] % mod << endl;


    return 0;
}

