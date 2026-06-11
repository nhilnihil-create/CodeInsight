#include <bits/stdc++.h>
#define FORUP(i, start, end) for (int i = start; i <= end; i++)
#define FORDOWN(i, end, start) for (int i = end; i >= start; i--)
#define mem(a, v) memset(a, v, sizeof a)
#define ll long long
#define ld long double
#define pir pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll MAX = 100009, MOD = 1000000007, BASE = 311, inf  = 1e9;

int du[] = {1, -1, 0, 0}, dv[] = {0, 0, -1, 1};
using namespace std;

ll n, k, a[109], f[109][MAX];

int main()
{
    //freopen("SUBXOR.inp", "r", stdin);
    //freopen("SUBXOR.out", "w", stdout);
    cin >> n >> k;
    FORUP(i, 1, n) cin >> a[i];

    f[0][0] = 1;
    FORUP(i, 1, n) {
        vector<ll> sum(k+9, 0);
        sum[0] = f[i-1][0];
        FORUP(j, 1, k) sum[j] = (sum[j-1] + f[i-1][j]) % MOD;
        FORUP(j, 0, k) {
            ll pos = j-a[i]-1;
            if(pos >= 0) f[i][j] = (sum[j] - sum[pos] + MOD*MOD) % MOD;
            else f[i][j] = sum[j] % MOD;
        }
    }

    cout << f[n][k] << endl;

    return 0;
}
