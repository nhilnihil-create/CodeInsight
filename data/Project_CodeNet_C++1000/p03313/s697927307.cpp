#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

int n, a[(1 << 18)], ans;

ii dp[(1 << 18)];

bool checkBit(int mask, int pos){
    if((mask & (1 << pos)))
        return 1;
    else
        return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < (1 << n); i++){
        cin >> a[i];
        dp[i].fi = a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (1 << n); j++){
            if(checkBit(j, i)){
                dp[j].se = max(dp[j].se, dp[(j ^ (1 << i))].fi);
                if(dp[j].se > dp[j].fi)
                    swap(dp[j].se, dp[j].fi);
            }
        }
    }
    for(int i = 1; i < (1 << n); i++){
        ans = max(ans, dp[i].se + dp[i].fi);
        cout << ans << "\n";
    }
}
