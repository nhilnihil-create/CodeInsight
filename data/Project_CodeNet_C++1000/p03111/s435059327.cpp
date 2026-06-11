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
    int N, A[3];
    cin >> N >> A[0] >> A[1] >> A[2];
    int l[8];
    rep(i, N) cin >> l[i];
    int ans = INF;
    int pattern = (1 << (N * 2));
    rep(k, pattern) {
        int cnt[3] = {};
        int bit = k;
        int sum[3] = {};
        rep(i, N) {
            int c = bit % 4;
            bit /= 4;
            if(c == 3) continue;
            cnt[c]++;
            sum[c] += l[i];
            
        }
        bool ok = true;
        int tmp = 0;
        rep(i, 3) {
            if(cnt[i] == 0) ok = false;
            tmp += (cnt[i] - 1) * 10;
            tmp += abs(A[i] - sum[i]);
        }
        if(!ok) continue;
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
