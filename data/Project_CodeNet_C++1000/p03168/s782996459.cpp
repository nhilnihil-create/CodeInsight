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
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

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

/* 
3
0.30 0.60 0.80

 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // if we had i tosses then tails = i - heads
    vector<double> dp(n + 1);
    dp[0] = 1;
    for (int coin = 0; coin < n; coin++) {
        double p_heads;
        cin >> p_heads;
        for (int i = coin + 1; i >= 0; i--) {
            dp[i] = (i == 0 ? 0 : dp[i - 1] * p_heads) + dp[i] * (1 - p_heads);
            // dp[i + 1] += p_heads * dp[i];
            // dp[i] = (1 - p_heads) * dp[i];
        }
    }
    double answer = 0;
    for (int heads = 0; heads <= n; ++heads) {
        int tails = n - heads;
        if (heads > tails) {
            answer += dp[heads];
        }
    }
    printf("%.10lf\n", answer);
}