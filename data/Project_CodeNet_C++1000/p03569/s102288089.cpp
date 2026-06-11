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
    string S; cin >> S;
    int ans = 0;
    int idx1 = 0;
    int idx2 = S.length() - 1;
    while(idx1 < idx2) {
        if (S[idx1] == S[idx2]) {
            idx1++;
            idx2--;
        }
        else if(S[idx1] == 'x' && S[idx2] != 'x') {
            idx1++;
            ans++;
        }
        else if (S[idx1] != 'x' && S[idx2] == 'x') {
            idx2--;
            ans++;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}
