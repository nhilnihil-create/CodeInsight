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

int sum[510][510];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, Q;
    cin >> N >> M >> Q;
    rep(i, M) {
        int L, R;
        cin >> L >> R;
        L--; R--;
        sum[L][R]++;
    }
    rep(i, N) {
        rep(j, N) {
            sum[i][j + 1] += sum[i][j];
        }
    }
    RREP(i, N - 1, 0) {
        rep(j, N) {
            sum[i][j] += sum[i + 1][j];
        }
    }
    while(Q--) {
        int L, R;
        cin >> L >> R;
        L--; R--;
        cout << sum[L][R] << endl;
    }


    return 0;
}
//  1   2   3
//1 +1 +1  +1
//2    +1
//3        +1

//  1   2   3
//1 1   2   3
//2     1   1
//3         1

//  1   2   3
//1 1   3   5
//2     1   2
//3         1