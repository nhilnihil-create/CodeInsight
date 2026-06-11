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

int dp[10010][10];
int cost[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> A;
int N, M;
int calc(int n, int m) {
    
    if(n < 0) return -INF;
    if(n == 0) return dp[n][m] = 0;
    if(dp[n][m] != -1) return dp[n][m];
    rep(i, M) {
        int c = calc(n - cost[A[i]], A[i]);
        dp[n][m] = max(dp[n][m], c + 1);
        //cout << A[i] << " " << n << " " << m << " " << dp[n][m] << " " << c + 1 << endl;
    }
    return dp[n][m];
}

void output(int n) {
    if(n <= 0) return;
    int len = -1;
    int num = 0;
    rep(i, M) {
        if(n - cost[A[i]] >= 0 && len < dp[n - cost[A[i]]][A[i]]) {
            len = dp[n - cost[A[i]]][A[i]];
            num = A[i] + 1;
        }
    }
    cout << num;
    //cout << num << " " << n << endl;
    output(n - cost[num - 1]);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    rep(i, M) {
        int a; cin >> a;
        a--;
        A.push_back(a);
    }
    sort(A.begin(), A.end(), greater<int>());
    rep(i, 10010) rep(j, 10) dp[i][j] = -1;
    rep(i, M) calc(N - cost[A[i]], A[i]);
    output(N);
    cout << endl;

    return 0;
}
