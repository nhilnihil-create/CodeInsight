#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// ############################################################################################

#define FOREACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define FORE(i, a, n) for (i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

#define mod 1000000007
#define inf 1e18

#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// ############################################################################################

ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res % mod;
}

void a_k_s() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

int dp[3005][3005];
string s, t;

string getLCS(int len) {
    string lcs;

    int i = 0, j = 0;
    while (len > 0) {
        if (s[i] == t[j]) {
            lcs += s[i];
            i++;
            j++;
            len--;
        } else {
            if (dp[i][j + 1] > dp[i + 1][j])
                j++;
            else
                i++;
        }
    }

    return lcs;
}

int lenLCS(int i, int j) {
    // Base Case
    if (i >= s.length() || j >= t.length())
        return 0;

    // Look Up
    if (dp[i][j] != -1)
        return dp[i][j];

    // Recursive Case
    if (s[i] == t[j])
        return dp[i][j] = 1 + lenLCS(i + 1, j + 1);
    else
        return dp[i][j] = max(lenLCS(i, j + 1), lenLCS(i + 1, j));
}

int main() {
    a_k_s();

    cin >> s >> t;

    memset(dp, -1, sizeof dp);

    int len = lenLCS(0, 0);

    cout << getLCS(len) << endl;

    return 0;
}