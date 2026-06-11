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
unsigned int randInt() {
	static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
	unsigned int tt = (tx ^ (tx << 11));
	tx = ty; ty = tz; tz = tw;
	return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}
int cnt[13] = {};
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int D[51];
    cnt[0]++;
    rep(i, N) {
        cin >> D[i];
        cnt[D[i]]++;
        if(cnt[D[i]] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    D[N] = 0;
    int ans = 0;
    int loop = 1000000;
    N++;
    while(loop--) {
        int k = randInt() % N;
        D[k] = 24 - D[k];
        int tmp = 24;
        rep(i, N) {
            REP(j, i + 1, N - 1) {
                int d = abs(D[i] - D[j]);
                tmp = min(tmp, min(d, 24 - d));
            }
        }
        // if(ans < tmp) {
        //     rep(i, N) cout << D[i] << " ";
        //     cout << endl;
        // }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    



    return 0;
}
