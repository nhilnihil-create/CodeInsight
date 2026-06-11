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
    int D, G;
    cin >> D >> G;
    int p[11], c[11];
    rep(i, D) cin >> p[i] >> c[i];
    int ans = INF;
    rep(bit, (1 << D)) {
        rep(i, D) {
            int score = 0;
            int cnt = 0;
            rep(j, D) {
                if (i == j) continue;
                if (bit & (1 << j)) {
                    score += p[j] * (j + 1) * 100;
                    score += c[j];
                    cnt += p[j];
                }
            }
            int tmp = p[i];
            //cout << bit << " " << score << " " << cnt << endl;
            while(score < G && tmp > 0) {
                score += (i + 1) * 100;
                tmp--;
                cnt++;
            }
            if(tmp == 0) score += c[i];
            //cout << bit << " " << score << " " << cnt << endl;
            if(score >= G) ans = min(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}
