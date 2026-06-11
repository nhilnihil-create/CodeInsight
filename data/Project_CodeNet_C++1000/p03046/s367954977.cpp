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
    int M, K;
    cin >> M >> K;
    if(M == 0) {
        if(K == 0) cout << "0 0" << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(M == 1)  {
        if(K == 0) cout << "0 0 1 1" << endl;
        else cout << -1 << endl;
        return 0;
    }
    int upper = (1 << M) - 1;
    if(upper < K) {
        cout << -1 << endl;
        return 0;
    }
    if(K == 0) {
        RREP(i, upper, 0) {
            if(i != upper) cout << " ";
            cout << i;
        }
        REP(i, 0, upper) {
            cout << " " << i;
        }
        return 0;
    }
    cout << "0 " << K << " 0";
    RREP(i, upper, 1) {
        if(i != K) {
            cout << " " << i;
        }
    }
    cout << " " << K;
    REP(i, 1, upper) {
        if(i != K) {
            cout << " " << i;
        }
    }
    cout << endl;


    


    return 0;
}
// 1 0: {0, 0, 1, 1}
// 1 1: x
// 2 0: {0, 1, 0, 3, 2, 1, 2, 3}
// 2 1: {0, 3, 1, 3, 2, 1}
// 3 7: {0, 7, 0, }
