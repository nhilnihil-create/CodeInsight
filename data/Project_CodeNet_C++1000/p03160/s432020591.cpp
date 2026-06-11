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
vector<int> h(N);
int dp[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int T = 1;
        //cin>>T;
        while(T--)
        {
                cin>>n;
                for(i = 1; i<=n; i++) {
                        cin>>h[i]; dp[i] = 0;
                }
                dp[1] = 0; dp[2] = abs(h[2] - h[1]);
                for(i = 3; i<=n; i++) dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
                cout<<dp[n]; 
        }
        return 0;
}