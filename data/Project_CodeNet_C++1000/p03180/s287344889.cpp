#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define endl "\n"

void precalculate(vector<vector<ll>>& arr, vector<ll>& cost) {
    ll n = arr.size();
    ll N = 1 << n;
    cost.resize(N);
    fill(cost.begin(), cost.end(), 0);
    for (ll bitmask = 1; bitmask < N; bitmask++) {
        for (ll i = 0; i < n; i++) {
            if (!(bitmask & (1 << i))) {
                continue;
            }
            for (ll j = i+1; j < n; j++) {
                if (bitmask & (1 << j)) {
                    cost[bitmask] += arr[i][j];
                }
            }
        }
    }
}

void build(ll i, ll bitmask, ll submask, vector<vector<ll>>& adj, ll n) {
    if (i == n) {
        if (__builtin_popcount(submask) != 0) {
            adj[bitmask].push_back(submask);
        }
        return;
    }

    build(i+1, bitmask, submask, adj, n);
    build(i+1, bitmask | (1 << i), submask, adj, n);
    build(i+1, bitmask | (1 << i), submask | (1 << i), adj, n);
}

ll recurse(ll bitmask, vector<vector<ll>>& adj, vector<bool>& visited, vector<ll>& cost, vector<ll>& dp) {
    if (bitmask == 0) {
        return 0;
    }
    if (visited[bitmask]) {
        return dp[bitmask];
    }

    visited[bitmask] = true;

    ll best = LLONG_MIN;

    for (auto submask: adj[bitmask]) {
        best = max(best, recurse(bitmask ^ submask, adj, visited, cost, dp) + cost[submask]); // same bitmask never comes, because submask is never 0
    }

    return dp[bitmask] = best;
}

int main(void) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll> (n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    ll N = 1 << n;

    // precalculate group costs
    vector<ll> cost;
    precalculate(arr, cost);

    // form possible subgroups for each group of left over individuals
    vector<vector<ll>> adj (N);
    build(0, 0, 0, adj, n);
    
    vector<ll> dp (N);
    vector<bool> visited (N, false);

    cout << recurse(N-1, adj, visited, cost, dp) << endl;



    return 0;
}