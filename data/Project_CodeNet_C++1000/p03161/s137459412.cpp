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

int n, i, j, k;
vector<int> h(N);
int dp[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int T = 1;
        //cin>>T;
        while(T--)
        {
                cin>>n>>k;
                for(i = 1; i<=n; i++) {
                        cin>>h[i]; dp[i] = INT_MAX;
                }
                dp[0] = dp[1] = 0;
                for(i = 2; i<=n; i++){
                        for(j = 1; j<=k; j++){
                                if(i > j) dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
                        }
                }
                cout<<dp[n];
        }
        return 0;
}