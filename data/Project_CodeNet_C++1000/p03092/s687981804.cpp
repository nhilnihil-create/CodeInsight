#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 100000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5005
int n;
ll a, b;
int p[MN];
int inv[MN];
ll dp[MN][MN]; //cost to get the first i to be in order and less than the jth thing

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0x3f, sizeof dp);

    cin >> n >> a >> b;
    FOR(i, 1, n){
        cin >> p[i];
        inv[p[i]] = i;
    }

    dp[0][1] = 0;
    F0R(i, n){
        FOR(j, 1, n+1){
            //cout << "best ans at " << i << " " << j << " is " << dp[i][j] << "\n";
            int loc = inv[i+1];
            //cout << "loc is " << loc << "\n";
            if(j <= loc){
                dp[i+1][loc+1] = min(dp[i+1][loc+1], dp[i][j]);
            }

            ll val = j <= loc ? b : a;

            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + val);
        }
    }
    ll mnv = INF;
    FOR(i, 1, n+1){
        mnv = min(mnv, dp[n][i]);
    }

    cout << mnv << "\n";

    return 0;
}
