#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin>>s;
    int n = s.size();

    vector<vector<ll>> dp(n+1, vector<ll>(4, 0));
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        // 使わない
        for(int j=0; j<4; j++){
            if(s[i] == '?') dp[i+1][j] += dp[i][j] * 3;
            else dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
        }

        // 使う
        if(s[i] == 'A' || s[i] == '?'){
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] %= MOD;
        }
        if(s[i] == 'B' || s[i] == '?'){
            dp[i+1][2] += dp[i][1];
            dp[i+1][2] %= MOD;
        }
        if(s[i] == 'C' || s[i] == '?'){
            dp[i+1][3] += dp[i][2];
            dp[i+1][3] %= MOD;
        }
    }

    cout << dp[n][3] << endl;

    return 0;
}