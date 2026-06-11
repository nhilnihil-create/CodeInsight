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
#define int long long
#define FALSE 0
#define TRUE 1

int dp[64][2];
int A[100010];
int N, K;
int calc(int bit, int smaller) {
    //cout << bit << " " << smaller << endl;
    if(bit < 0) return 0;
    if(dp[bit][smaller] != -1) return dp[bit][smaller];
    int ret1 = 0, ret2 = 0;
    rep(i, N) {
        int c1 = A[i] & (1LL << bit);
        int c2 = K & (1LL << bit);
        ret1 += c1 ^ c2;
    }
    rep(i, N) {
        int c1 = A[i] & (1LL << bit);
        int c2 = 0;
        if(!(K & (1LL << bit))) c2 = (1LL << bit);
        ret2 += c1 ^ c2;
    }
    if(smaller) 
        return dp[bit][smaller] = calc(bit - 1, TRUE) + max(ret1, ret2);
    if(K & (1LL << bit))
        return dp[bit][smaller] = max(calc(bit - 1, FALSE) + ret1, calc(bit - 1, TRUE) + ret2);
    return dp[bit][smaller] = calc(bit - 1, FALSE) + ret1;
}


signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> K;
    
    rep(i, N) cin >> A[i];
    rep(i, 64) rep(j, 2) dp[i][j] = -1;
    cout << calc(60, FALSE) << endl;

    return 0;
}
