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
    string s; cin >> s;
    if(s.back() == '1' || s.front() == '0') {
        cout << "-1" << endl;
        return 0;
    }
    int n = s.length() - 1;
    rep(i, n / 2) {
        if (s[i] != s[n - i - 1]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    int l = 1, r = 2;
    rep(i, n) {
        if(s[i] == '1') {
            cout << l << " " << r << endl;
            l = r;
            r++;
        } else {
            cout << l << " " << r << endl;
            r++;
        }
    }


    return 0;
}
