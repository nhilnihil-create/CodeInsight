#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

bool check(vector<int> d, int x) {
    int sum = 0;
    int N = d.size();
    if (N == 0) return x == 0;
    rep(i,N) sum += d[i];
    if ((x + sum) % 2 == 1) return false;
    int S = (x + sum) / 2;

    vector<vector<bool>> dp(N, vector<bool>(S + 1, false));
    dp[0][0] = true;
    dp[0][d[0]] = true;
    for (int i = 1; i < N; i++) for (int j = 0; j <= S; j++) {
        if (dp[i - 1][j]) dp[i][j] = true;
        if (j - d[i] >= 0 && dp[i - 1][j - d[i]]) dp[i][j] = true;
    }
    return dp[N - 1][S];
}

int main() {

    string S;
    cin >> S;
    int N = S.length();
    int x, y;
    cin >> x >> y;

    vector<vector<int>> d(2);
    int count = 0;
    bool isX = true;
    bool isInit = true;

    rep(i,N) {
        if (S[i] == 'F') count++;
        else if (isInit) {
            x -= count;
            count = 0;
            isX = false;
            isInit = false;
        } else {
            if (count > 0) {
                if (isX) d[0].push_back(count);
                else d[1].push_back(count);
                count = 0;
            }
            isX = !isX;
        }
    }
    if (isInit) {
        x -= count;
        count = 0;
        isX = false;
        isInit = false;
    }
    if (count > 0) {
        if (isX) d[0].push_back(count);
        else d[1].push_back(count);
    }
    count = 0;
    isX = !isX;

    if (check(d[0], abs(x)) && check(d[1], abs(y))) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}