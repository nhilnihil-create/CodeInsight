#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

int dp[18][2];

int main(){
    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = s[0] - '0';
    dp[0][1] = s[0] - '1';
    rep(i, n) {
        if (i==0) continue;
        if (s[i]=='0') {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + 9;
            continue;
        }
        dp[i][0] = dp[i-1][0] + (s[i]-'0');
        dp[i][1] = dp[i-1][1] + 9;
        dp[i][1] = max(dp[i][1], dp[i-1][0] + (s[i]-'1'));
    }
    int ans = max(dp[n-1][0], dp[n-1][1]);
    
    cout << ans << endl;
    return 0;
}
