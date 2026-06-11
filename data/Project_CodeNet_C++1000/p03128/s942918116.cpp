#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define per(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 2e9
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, m) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> need(10);
    need[1] = 2; need[2] = 5; need[3] = 5; need[4] = 4;
    need[5] = 5; need[6] = 6; need[7] = 3; need[8] =7; need[9] = 6;

    vector<int> dp(n+1, -INF); //i本使うときの桁数の最大値
    dp[0] = 0;
    rep(i, n+1) {
        rep(j, m) {
            if (i < need[a[j]]) continue;
            dp[i] = max(dp[i], dp[i-need[a[j]]]+1);
        }
    }
    string ans = "";
    int remain = dp[n];
    int match = n;

    while (match > 0) {
        per(i, m) {
            if (match < need[a[i]]) continue;
            if (dp[match-need[a[i]]] == remain-1) {
                ans += char('0' + a[i]);
                match -= need[a[i]];
                remain--;
                break;
            }
        }
    }
    cout << ans << endl;

}