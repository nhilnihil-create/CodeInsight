#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> w(n), e(n);
    for (int i = 0; i <= n-2; i++) {
        if (s[i] == 'W') w[i+1] = w[i] + 1;
        else w[i+1] = w[i];
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i <= n-2; i++) {
        if (s[i] == 'E') e[i+1] = e[i] + 1;
        else e[i+1] = e[i];
    }
    reverse(s.begin(), s.end());
    int ans = INF;
    rep(i,n) {
        int now = w[i] + e[n-i-1];
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}