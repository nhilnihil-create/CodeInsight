// {{{ by unolight
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-variable"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

int main() {
    LL n, p;
    cin >> n >> p;
    if ( n==1 ) {
        cout << p << '\n';
        return 0;
    }

    map<int,int> mp;
    for ( LL i=2; i*i<=p; i++ ) {
        while ( p&&p%i==0 ) {
            p/=i;
            mp[i]++;
        }
    }
    if ( p>1 ) mp[p]++;

    LL ans=1;
    for ( auto &p:mp ) {
        int cnt=p.second/n;
        if ( cnt>0 ) {
            REP(i,cnt) {
                ans*=p.first;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

// 2^3*3




