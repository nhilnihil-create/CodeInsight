#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

bool f(vector<int> vec, int target) {
    int s = 0;
    rep(i, vec.size()) {
        s += vec[i];
    }
    if (s < target)return false;
    if (s == target)return true;
    int dist = s - target;
    if (dist % 2 == 1)return false;
    dist /= 2;
    sort(vec.begin(), vec.end());
    bool dp[vec.size() + 1][dist + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    rep(i, vec.size()) {
        rep(j, dist + 1) {
            dp[i + 1][j] = dp[i][j];
            if (j - vec[i] >= 0)dp[i + 1][j] |= dp[i][j - vec[i]];
        }
    }
    return dp[vec.size()][dist];
}

signed main() {
    string S;
    cin >> S;
    int X, Y;
    cin >> X >> Y;
    int k = 0;
    while (S[k] == 'F') {
        k++;
        --X;
    }
    X = abs(X);
    Y = abs(Y);
    vector<int> lr, ud;
    bool nowX = true;
    int length = 0;
    for (;;) {
        while (k < S.size() && S[k] == 'F') {
            k++;
            length++;
        }
        k++;
        if (nowX && length != 0)lr.push_back(length);
        if (!nowX && length != 0)ud.push_back(length);
        nowX = !nowX;
        length = 0;
        if (k >= S.size())break;
    }
    if (f(lr, X) && f(ud, Y)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
