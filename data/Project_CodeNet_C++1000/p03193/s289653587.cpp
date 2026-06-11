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
    int n;
    LL h,w;
    cin >> n >> h >> w;
    int ans=0;
    for ( int i=0; i<n; i++ ) {
        LL a,b;
        cin >> a >> b;
        if ( a>=h&&b>=w ) ans++; 
    }
    cout << ans << '\n';
    return 0;
}




