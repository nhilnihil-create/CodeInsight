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

int c[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[5010][10010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int A[10];
    
    
    rep(i, 5010) rep(j, 10010) dp[i][j] = -INF;
    dp[0][N] = 0;
    rep(i, M) cin >> A[i];
    sort(A, A + M, greater<int>());
    for(int i = 0; i < N/2; i++) {        
        for(int k = 10000; k >= 0; k--) {
            for(int j = 0; j < M; j++) {
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
                int cost = k - c[A[j]];
                if(cost >= 0) {
                    dp[i + 1][cost] = max(dp[i + 1][cost], dp[i][k] + 1);
                }
            }
        }
    }
    string T;
    int num = 0;
    for(int i = N/2; i > 0; i--) {
        for(int j = 0; j < M; j++) {
            if(dp[i][num] == dp[i - 1][num + c[A[j]]] + 1) {
                num += c[A[j]];
                T += (char)('0' + A[j]);
                break;
            }
        }
    }
    cout << T << endl;



    return 0;
}
