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
            int tmp = 0;
            int cnt = 0;
            rep(j, D) {
                if(bit & (1 << j)) {
                    if(i != j) {
                        tmp += p[j] * (j + 1) * 100;
                        tmp += c[j];
                        cnt += p[j];
                    }
                }
            }
            //cout << "*" << bitset<2>(bit) << " " << tmp << " " << cnt << endl;
            if(bit & (1 << i)) {
                int solved = 0;
                while(tmp < G && solved < p[i]) {
                    tmp += (i + 1) * 100;
                    solved++;
                    cnt++;
                    if(solved == p[i]) tmp += c[i];
                }
            }
            if(tmp >= G) ans = min(ans, cnt);
            //cout << bitset<2>(bit) << " " << tmp << " " << cnt << endl;
        }
        
    }
    cout << ans << endl;

    return 0;
}
