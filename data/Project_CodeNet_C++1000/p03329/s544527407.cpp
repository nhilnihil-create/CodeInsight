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
    int N; cin >> N;
    int ans = N;
    REP(i, 0, N) {
        int A = i, B = N - i;
        int k = 6 * 6 * 6 * 6 * 6 * 6;
        int cnt = 0;
        while(A > 0) {
            while(A - k >= 0) {A -= k; cnt++;}
            k /= 6;
        }
        k = 9 * 9 * 9 * 9 * 9;
        while(B > 0) {
            while(B - k >= 0) {B -= k; cnt++;}
            k /= 9;
        }
        ans = min(ans, cnt);
        //cout << i << " " << N - i << " " << cnt << endl;
    }
    cout << ans << endl;

    return 0;
}
