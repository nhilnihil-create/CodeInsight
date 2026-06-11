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
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;
    while(Q--) {
        int countD = 0, countM = 0, countDM = 0, ans = 0;
        int k; cin >> k;
        vector<int> addDM(1000010, 0);
        rep(i, N) {
            if (S[i] == 'D') countD++;
            else if (S[i] == 'M') {
                countM++; 
                countDM += countD;
                addDM[i] = countD;
            }
            else if (S[i] == 'C') ans += countDM;

            if (i < k - 1) continue;
            if (S[i - k + 1] == 'D') {
                countD--;
                countDM -= countM;
            }
            else if (S[i - k + 1] == 'M') {
                countM--;
            }
            //cout << i << " " << countD << " " << countM << " " << countDM << " " << ans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
