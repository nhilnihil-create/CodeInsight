#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

const int match[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const string SINF = "-";

vector<string> dp(10100, SINF);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    dp[0] = "";
    for(int i = 0; i <= n; i++) {
        if(dp[i] == SINF) {
            continue;
        }
        for(int j = 0; j < m; j++) {
            if(i + match[a[j]] <= n) {
                string tmp = dp[i] + to_string(a[j]);
                int nxt = i + match[a[j]];
                if(dp[nxt].size() < tmp.size() ||
                   (dp[nxt].size() == tmp.size() && dp[nxt] < tmp)) {
                    dp[nxt] = tmp;
                }
            }
        }
    }
    cout << dp[n] << endl;
}