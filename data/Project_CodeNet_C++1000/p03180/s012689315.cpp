// Math = ♥️

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define pq priority_queue
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(c) ((ll)c.size())
#define ordered_set                            \
    tree<ll, null_type, less<ll>, rb_tree_tag, \
         tree_order_statistics_node_update>

int main(void) {
    ll n;
    cin >> n;

    ll arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    ll MAX = (1 << n);
    ll sub[MAX];

    for (int i = 0; i < MAX; i++) {
        sub[i] = 0;
        vi ind;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ind.pb(j);
            }
        }

        for (int j = 0; j < ind.size(); j++) {
            for (int k = j + 1; k < ind.size(); k++) {
                sub[i] += arr[ind[j]][ind[k]];
            }
        }
    }

    ll dp[MAX];

    for (int mask = 0; mask < MAX; mask++) {
        dp[mask] = sub[mask];
        for (int s = mask; s; s = (s - 1) & mask) {
            dp[mask] = max(dp[mask], sub[mask ^ s] + dp[s]);
        }
    }

    cout << dp[MAX - 1] << "\n";
}

