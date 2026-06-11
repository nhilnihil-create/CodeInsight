#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int MX = 0;
    int MN = INF;
    int cnt[3] = {};
    rep(i, S.length()) {
        cnt[S[i] - 'a']++;
    }
    int zerocnt = 0;
    rep(i, 3){
        if (cnt[i] == 0) zerocnt++;
        MX = max(cnt[i], MX);
        MN = min(cnt[i], MN);
    }
    if (zerocnt == 2) {
        if (S.length() == 1) {
            cout << "YES" << endl;
            return 0;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    } else if (zerocnt == 1) {
        if ( S.length() == 2) {
            cout << "YES" << endl;
            return 0;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    } else {
        if (MX - MN <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
