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
    ll n; cin >> n;
    string S;
    if (n == 0) {cout << 0 << endl; return 0;}
    int cnt = 0;
    while(n != 0) {
        if(cnt % 2 == 0) {
            if((n + INF) % 2 == 1) S = "1" + S;
            else S = "0" + S;
            n -= (n + INF) % 2;
            n /= 2;
        } else {
            if((n + INF) % 2 == 1) S = "1" + S;
            else S = "0" + S;
            n += (n + INF) % 2;
            n /= 2;
        }
        cnt++;
        //cout << S << " " << cnt << endl;
    }
    cout << S << endl;



    return 0;
}
// -1
// 