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


int cnt[110];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    REP(i, 2, N) cnt[i]++;
    REP(i, 2, N) {
        int n = i;
        int j = 2;  
        while(n > 1) {
            while (n % j == 0) {
                cnt[j]++;
                n /= j;
            }
            j++;
        }
    }
    //REP(i, 2, N) cout << i << " " << cnt[i] << endl;
    int ans = 0;
    REP(i, 2, N) {
        if (cnt[i] >= 75) ans++; 
    }
    REP(i, 2, N) {
        REP(j, i + 1, N) {
            if (cnt[i] >= 3 && cnt[j] >= 25) ans++;
            if (cnt[i] >= 25 && cnt[j] >= 3) ans++;
        }
    }
    REP(i, 2, N) {
        REP(j, i + 1, N) {
            if (cnt[i] >= 15 && cnt[j] >= 5) ans++;
            if (cnt[i] >= 5 && cnt[j] >= 15) ans++;
        }
    }
    REP(i, 2, N) {
        REP(j, i + 1, N) {
            REP(k, j + 1, N) {
                if (cnt[i] >= 3 && cnt[j] >= 5 && cnt[k] >= 5) ans++;
                if (cnt[i] >= 5 && cnt[j] >= 3 && cnt[k] >= 5) ans++;
                if (cnt[i] >= 5 && cnt[j] >= 5 && cnt[k] >= 3) ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
