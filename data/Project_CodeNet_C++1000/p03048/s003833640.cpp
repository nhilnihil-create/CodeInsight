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
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    REP(i, 0, n) {
        REP(j, 0, n) {
            int remain = n - i * r - j * g;
            if(remain < 0) continue;
            if(remain % b == 0) {
                ans++;
                //cout << i << " " << j << " " << remain / b << endl;
            }
        }
    }
    cout << ans << endl;


    return 0;
}
