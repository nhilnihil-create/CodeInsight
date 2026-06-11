#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<ull> vul;
#define For(i, n) for(ll i = 0; i < n; i++)
#define len(n) (ll)(n).size()
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define Sort(a) sort(a.begin(), a.end())

vector<ull> slimes;
ull pref_sizes[401];
ull dp[400][400];

int main() {
    FAST_IO;
    ll N;
    cin >> N;
    For(l, N) For(r, N) dp[l][r] = 1e15;
    For(i, N) {
        ull size;
        cin >> size;
        slimes.push_back(size);
        dp[i][i] = 0;
        if (i) pref_sizes[i] = pref_sizes[i - 1] + slimes[i];
        else pref_sizes[i] = slimes[i];
    }
    for(ll r = 0; r < N; r++) {
        for(ll l = r; l >= 0; l--) {
            for(ll m = l; m < r; m++) {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] + (pref_sizes[r] - pref_sizes[l - 1]));
            }
        }
    }
    cout << dp[0][N - 1] << '\n';
    return 0;
}