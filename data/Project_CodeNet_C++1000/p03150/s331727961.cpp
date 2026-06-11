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
    string K;
    int n = S.length();
    rep(i, n + 1) {
        REP(k, i + 1, n + 1) {
            string T = K;
            REP(j, k, n - 1) {
                T += S[j];
            }
            if(T == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
            //cout << T << endl;
        }
        if(i < n)
        K += S[i];
    }
    cout << "NO" << endl;

    return 0;
}
