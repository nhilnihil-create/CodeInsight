#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)

typedef long long ll;

const int N = 5050;


#define left __nico_left
#define right __nico_right
int n, p[N], r[N], left, right;
ll dp[N][N], gt[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >>n >> right >> left;
    forn(i,n) {
        cin >>p[i];
        --p[i];
        r[p[i]] = i;
    }
    forn(i,n) {
        int pos = r[i];
        for (int j = pos-1; j >= 0; j--) {
            gt[i][j] = gt[i][j+1] + (p[j] > p[pos]);
        }
    }

    for (int from = n-1; from >= 0; from--) {
        for (int first = n-1; first >= 0; first--) {
            if (r[first] < from) {
                dp[from][first] = dp[from][first+1];
            }
            else {
                ll cost = gt[first][from] > 0 ? left : 0;
                dp[from][first] = min(
                    cost + dp[from][first+1],
                    (ll) right * gt[first][from] + dp[r[first]+1][first]
                );
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
