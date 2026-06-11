#include "bits/stdc++.h"
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
        int l, r;
        cin >> l >> r;
        sum[r][l]++;
    }
    // rep(i, N + 1) {
    //     rep(j, N + 1) {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    rep(i, N) {
        rep(j, N + 1) {
            sum[i + 1][j] += sum[i][j];
        }
    }
    rep(i, N + 1) {
        RREP(j, N, 1) {
            sum[i][j - 1] += sum[i][j];
        }
    }
    // rep(i, N + 1) {
    //     rep(j, N + 1) {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while(Q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r][l] << endl;
    }


    return 0;
}

// |
// |-|
//   |

// |-|-|-|-|
//   |-|-|-|-|-|-|
//             |-|-|-|
// |-------------|
//     |-------------|

//  0 1 2
//0   
//1   1 1
//2     1

//  0 1 2
//0   
//1   1 3
//2     1

//  0 1 2 3 4 5 6 7 8 9 10
//0 0 0
//1 0 0
//2 0 0
//3 0 0
//4 1 1 0 0 0 0 0 0 0 0 0
//5 1 1
//6 1 1
//7 1 1
//8 1 1
//9 1 1
//10

