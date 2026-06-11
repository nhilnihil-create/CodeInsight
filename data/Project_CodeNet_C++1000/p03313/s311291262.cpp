#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    nfs
    int i, j, n;
    cin >> n;
    vector <pair<int,int>> dp((1 << n), {0, 0});
    
    for (i = 0; i < (1 << n); i++) {
        cin >> dp[i].ff;
    }

    for (i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) {
                int a[2] = {dp[mask ^ (1 << i)].ff, dp[mask ^ (1 << i)].ss};
                for (j = 0; j < 2; j++) {
                    if (a[j] > dp[mask].ss) {
                        dp[mask].ss = a[j];
                        if(dp[mask].ss > dp[mask].ff)
                            swap(dp[mask].ff, dp[mask].ss);
                    }
                    else break;
                }
            }
        }
    }

    int out = dp[0].ff + dp[0].ss;
    for (i = 1; i < (1 << n); i++) {
        cout << (out = max(out, dp[i].ff + dp[i].ss)) << " ";
    }
}