#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sz(x) (long long)x.size()
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 5;
const ld pi = 3.141592653;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = __LONG_LONG_MAX__;

using namespace std;

int dx[9] = {1, -1, 0, 0, 1, 1, -1, -1, 0};
int dy[9] = {0, 0, 1, -1, 1, -1, 1, -1, 0};

int n, i;
vector<int> a(N), b(N), c(N);
int dp[N][3];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int T = 1;
        //cin>>T;
        while(T--)
        {
                cin>>n;
                for(i = 1; i<=n; i++) cin>>a[i]>>b[i]>>c[i];
                for(i = 0; i<=n; i++) dp[i][0] = dp[i][1] = dp[i][2] = 0;
                dp[1][0] = a[1]; dp[1][1] = b[1]; dp[1][2] = c[1];
                for(i = 2; i<=n; i++){
                        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
                        dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + b[i];
                        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
                }
                cout<<max({dp[n][0], dp[n][1], dp[n][2]});
        }
        return 0;
}