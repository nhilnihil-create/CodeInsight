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
#define pqs priority_queue<int, vi, greater<int> >

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

double dp[301][301][301];

double solve(int x, int y, int z, int n) {
    if (x < 0 || y < 0 || z < 0) {
        return 0;
    }

    if (x == 0 && y == 0 && z == 0) {
        return 0;
    }

    if (dp[x][y][z] > -0.9) {
        return dp[x][y][z];
    }

    double exp = n + x * solve(x - 1, y, z, n) + y * solve(x + 1, y - 1, z, n) + z * solve(x, y + 1, z - 1, n);
    exp /= (x + y + z);

    return dp[x][y][z] = exp;
}

int main() {
    a_k_s();

    int n, x;
    cin >> n;
    memset(dp, -1, sizeof dp);

    int one = 0, two = 0, three = 0;

    FOR(i, 1, n + 1) {
        cin >> x;
        if (x == 1)
            one++;
        else if (x == 2)
            two++;
        else
            three++;
    }

    cout << fixed << setprecision(10) << solve(one, two, three, n) << endl;

    return 0;
}