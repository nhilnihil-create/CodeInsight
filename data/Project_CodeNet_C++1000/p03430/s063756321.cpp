#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// ordered_set X;
// *X.find_by_order(i) = ith largest element (counting from zero)
// X.order_of_key(k) = number of items in X < k (strict lt)
int main(){
    string S;
    int K;

    cin >> S;
    cin >> K;

    int N = S.length();

    vi dpr1(K+1, 0);
    vvi dpr2(N+1, dpr1);
    vector<vvi> dp(N+1, dpr2); // dp[i][j][k]

    for (int len=1;len<=N;len++) {
        for (int i=0;i+len<=N;i++) {
            for(int k=0;k<=K;k++) {
                int j = i+len;
                if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);

                if (S[i] == S[i+len-1]) {
                    if (len == 1) dp[i][j][k] = max(dp[i][j][k], 1 + dp[i+1][j-1][k]);
                    else dp[i][j][k] = max(dp[i][j][k], 2 + dp[i+1][j-1][k]);
                }

                dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i+1][j][k]);

                if (k > 0) {
                    if (len == 1) dp[i][j][k] = max(dp[i][j][k], 1 + dp[i+1][j-1][k-1]);
                    else dp[i][j][k] = max(dp[i][j][k], 2 + dp[i+1][j-1][k-1]);
                }
            }
        }
    }

    cout << dp[0][N][K] << endl;
    
}
