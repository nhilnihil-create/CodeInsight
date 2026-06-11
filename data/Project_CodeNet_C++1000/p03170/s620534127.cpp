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
#define FIRST 1
#define SECOND 0
int N, K;
int a[110];
int dp[100010][2];
int game(int x = K, int turn = FIRST) {
    if(dp[x][turn] != -1) return dp[x][turn];
    rep(i, N) {
        int n = x - a[i];
        if(n >= 0 && game(n, !turn) == turn) {
            return dp[x][turn] = turn;
        }
    }
    return  dp[x][turn] = !turn;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> K;
    rep(i, N) cin >> a[i];
    rep(i, 100010) rep(j, 2) dp[i][j] = -1;
    if(game() == FIRST) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }


    return 0;
}
