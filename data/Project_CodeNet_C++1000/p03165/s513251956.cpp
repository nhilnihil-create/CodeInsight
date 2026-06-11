#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int dp[3010][3010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    int n1 = S.length();
    int n2 = T.length();
    rep(i, n1) {
        rep(j, n2) {
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            if(S[i] == T[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
        }
    }

    string K;
    int i = n1, j = n2;
    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i][j - 1]) {
            j--;
        } else if(dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if(dp[i][j] == dp[i - 1][j - 1] + 1) {
            K = T[j - 1] + K;
            i--; j--;
        } else {
            return 0;
        }
    }
    cout << K << endl;

    return 0;
}
