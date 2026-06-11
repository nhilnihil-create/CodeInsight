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
    int N, M;
    cin >> N >> M;
    int s[10][10];
    int k[10];
    int p[10];
    rep(i, M) {
        cin >> k[i];
        rep(j, k[i]) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    rep(i, M) cin >> p[i];
    int ans = 0;
    rep(bit, (1 << N)) {
        int cnt[10] = {};
        rep(i, N) {
            if(!(bit & (1 << i))) continue;
            rep(j, M) {
                rep(t, k[j]) {
                    if(s[j][t] == i) cnt[j]++;
                }
            }
        }
        bool ok = true;
        rep(i, M) {
            if(cnt[i] % 2 != p[i]) ok = false;
        }
        ans += ok;
    }  
    cout << ans << endl;

    return 0;
}
