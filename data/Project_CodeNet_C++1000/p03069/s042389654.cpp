#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int cumulative_sum_white[220000];
Int cumulative_sum_black[220000];

int main() {
    int n;
    string s;
    cin >> n >> s;

    rep(i,n) {
        if (s[i] == '.') {
            cumulative_sum_white[i+1] = cumulative_sum_white[i] + 1;
            cumulative_sum_black[i+1] = cumulative_sum_black[i]; 
        }
        else {
            cumulative_sum_black[i+1] = cumulative_sum_black[i] + 1;
            cumulative_sum_white[i+1] = cumulative_sum_white[i];
        }
    }
    Int ans = LINF;
    for (int i = 0; i < n+1; i++) {
        Int change = cumulative_sum_black[i] + cumulative_sum_white[n] - cumulative_sum_white[i];
        ans = min(ans, change);
    }
    cout << ans << endl;
}