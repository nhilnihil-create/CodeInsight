#include <bits/stdc++.h>

#define REP( i, n )     for( int (i) = 0; (i) < (n); (i)++ )
#define ALL( a )        (a).begin(), (a).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

template<class T>bool chmax( T& a, const T& b ) { if( a < b ) { a = b; return 1; } return 0; }
template<class T>bool chmin( T& a, const T& b ) { if( a > b ) { a = b; return 1; } return 0; }

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main(){
    int a, b, c; cin >> a >> b >> c;
    if( a < c && c < b || b < c && c < a ) cout << "Yes" << endl;
    else cout << "No" << endl;
}
