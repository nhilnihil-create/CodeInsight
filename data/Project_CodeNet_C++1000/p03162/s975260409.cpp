#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define found(u, val) u.find(val) != u.end()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ar[n][3];
    for (int tr = 0; tr < n; tr++) {
        cin >> ar[tr][0] >> ar[tr][1] >> ar[tr][2];
    }

    int dp[n + 1][3];
    dp[n][0] = dp[n][1] = dp[n][2] = 0;

    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = ar[i][0] + max(dp[i + 1][1], dp[i + 1][2]);
        dp[i][1] = ar[i][1] + max(dp[i + 1][0], dp[i + 1][2]);
        dp[i][2] = ar[i][2] + max(dp[i + 1][1], dp[i + 1][0]);
    }
    int i = 0;
    cout << max(dp[0][0], max(dp[i][1], dp[i][2]));
}