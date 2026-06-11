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

string stmax(string a, string b) {
    if (a.size() > b.size()) return a;
    else if (a.size() < b.size()) return b;
    else {
        rep(i,a.size()) {
            if (a[i] == b[i]) continue;
            else {
                int x = a[i]-'0', y = b[i]-'0';
                if (x > y) return a;
                else return b;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> match = {0,2,5,5,4,5,6,3,7,6};
    vector<string> dp(n+1, "0");
    dp[0] = "";
    rep(i,n) {
        if (dp[i] == "0") continue;
        for (int x : a) {
            if (i+match[x] > n) continue;
            dp[i+match[x]] = stmax(dp[i+match[x]], dp[i]+char('0' + x));
        }
    }
    cout << dp[n] << endl;
    return 0;
}