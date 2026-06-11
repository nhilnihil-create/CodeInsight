#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
const ll MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x);
        }
        p = p >> 1;
        x = (x*x);
    }
    return res;
}
int a[17][17];
ll  maskanswer[(1 << 17)];
vector<vector<int>> maskChildren;
int n;
ll dp[(1 << 17)];
bool done[(1 << 17)];
void bruteChild(int mask, int pos, int original) {
    if (pos == n)
        return;
    if (mask != original)
        maskChildren[original].push_back(mask);
    if ((1 << pos) & mask) {
        bruteChild(mask & (~(1 << pos)), pos + 1, original);

    }
    bruteChild(mask, pos + 1, original);
}

void bruteMask(int mask) {

    if (maskChildren[mask].size() != 0) return;
    bruteChild(mask, 0, mask);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) continue;
        for (int j = i + 1; j < n; j++) {
            if (!(mask & (1 << j))) continue;
            ans += a[i][j];
        }
    }
    maskanswer[mask] = ans;
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            int child = mask & (~(1 << i));
            bruteMask(child);
        }
    }
}

ll solve(int mask) {
    if (!mask) return 0;
    if (done[mask]) return dp[mask];
    done[mask] = 1;
    ll ans = max(maskanswer[mask], (ll)0);
    for (int child: maskChildren[mask]) {
        ans = max(ans, solve(child ^ mask) + maskanswer[child]);
    }
    return dp[mask] = ans;
}


int main() {
    IO;
    cin >> n;
    maskChildren.resize(1 << n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    bruteMask((1 << n) - 1);
    cout << solve((1 << n) - 1);
    return 0;
}
