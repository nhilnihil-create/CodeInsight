#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(1.0);
const int limit = 100010;

#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define smaller_queue  priority_queue <ll, vector<ll>, greater<ll> >
//------------------------------------------------------

int main() {
    int n;
    cin >> n;
    int a[n];
    int Max = 0;
    int Min = INF;
    int Max_pos, Min_pos;
    bool all_positive = true;
    bool all_negative = true;

    rep(i, n) {
        cin >> a[i];
        if (a[i] > Max) {
            Max = a[i];
            Max_pos = i + 1;
        }
        if (a[i] < Min) {
            Min = a[i];
            Min_pos = i + 1;
        }
        if (a[i] < 0) all_positive = false;
        if (a[i] > 0) all_negative = false;
    }

    if (all_positive) {
        printf("%d\n", n - 1);
        for (int i = 1; i < n; ++i) printf("%d %d\n", i, i + 1);
    } else if (all_negative) {
        printf("%d\n", n - 1);
        for (int i = n; i > 1; --i) printf("%d %d\n", i, i - 1);
    } else if (Max >= -Min) {
        printf("%d\n", 2 * n - 1);
        for (int i = 1; i <= n; ++i) printf("%d %d\n", Max_pos, i);
        for (int i = 1; i < n; ++i) printf("%d %d\n", i, i + 1);
    } else {
        printf("%d\n", 2 * n - 1);
        for (int i = 1; i <= n; ++i) printf("%d %d\n", Min_pos, i);
        for (int i = n; i > 1; --i) printf("%d %d\n", i, i - 1);
    }

    return 0;
}

