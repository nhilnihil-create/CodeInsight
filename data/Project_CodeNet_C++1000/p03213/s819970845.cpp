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

int cnt[110];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    REP(i, 1, N) {
        int num = i;
        int j = 2;
        while(num > 1) {
            while(num % j == 0) {
                cnt[j]++;
                num /= j;
            }
            j++;
        }
    }
    int ans = 0;
    REP(i, 2, 100) {
        if(cnt[i] >= 74) ans++;
    }
    REP(i, 2, 100) {
        REP(j, 2, 100) {
            if(i >= j) continue;
            if(cnt[i] >= 2 && cnt[j] >= 24) ans++;
            if(cnt[i] >= 4 && cnt[j] >= 14) ans++;
            if(cnt[i] >= 24 && cnt[j] >= 2) ans++;
            if(cnt[i] >= 14 && cnt[j] >= 4) ans++;
        }
    }
    REP(i, 2, 100) {
        REP(j, 2, 100) {
            if(i >= j) continue;
            REP(k, 2, 100) {
                if(i >= k || j >= k) continue;
                if(cnt[i] >= 2 && cnt[j] >= 4 && cnt[k] >= 4) ans++;
                if(cnt[i] >= 4 && cnt[j] >= 2 && cnt[k] >= 4) ans++;
                if(cnt[i] >= 4 && cnt[j] >= 4 && cnt[k] >= 2) ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
// 75 = 3 * 5 * 5
// (74), (2, 24), (14, 4), (2, 4, 4)