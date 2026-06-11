#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    int N;
    cin >> N;

    double prob[N + 1];
    double dp[N + 1][N + 1], res = 0;

    for (int i = 1; i <= N; ++i)
        cin >> prob[i];

    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= N; ++j)
            dp[i][j] = 0;
    }

    dp[1][0] = 1.0 - prob[1];
    for (int i = 2; i <= N; ++i)
        dp[i][0] = dp[i - 1][0] * (1.0 - prob[i]);

    dp[1][1] = prob[1];
    for (int i = 2; i <= N; ++i)
        dp[i][i] = dp[i - 1][i - 1] * prob[i];

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j < i; ++j)
            dp[i][j] = dp[i - 1][j] * (1.0 - prob[i]) + dp[i - 1][j - 1] * prob[i];
    }

    for (int i = N / 2 + 1; i <= N; ++i)
        res += dp[N][i];

    cout << fixed << setprecision(10) << res;

    return 0;
}