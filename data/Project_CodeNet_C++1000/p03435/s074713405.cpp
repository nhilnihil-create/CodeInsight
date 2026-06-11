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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int c[3][3];
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    rep(i, 2) {
        rep(j, 2) {
            if(c[i][j] - c[i][j + 1] != c[i + 1][j] - c[i + 1][j + 1]) {
                cout << "No" << endl;
                return 0; 
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
// a1+b1 a1+b2 a1+b3
// a2+b1 a2+b2 a2+b3
// a3+b1 a3+b2 a3+b3
