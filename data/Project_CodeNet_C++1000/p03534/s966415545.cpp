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
    int len = S.length();
    if (len == 1) {
        cout << "YES" << endl;
        return 0;
    }
    int cnt[3] = {};
    rep(i, S.length()) {
        cnt[S[i] - 'a']++;
    }
    sort(cnt, cnt + 3, greater<int>());
    if (cnt[1] == 0) {
        cout << "NO" << endl;
    } else if (cnt[2] == 0) {
        if(len == 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (cnt[0] - cnt[2] < 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
