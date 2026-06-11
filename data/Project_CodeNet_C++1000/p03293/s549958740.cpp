#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
#define rep(n) for( int i = 0 ; i < n ; i++ )
#define REP(n) for( int i = 1 ; i <= n ; i++ )
#define repll(n) for( ll i = 0 ; i < n ; i++ )
#define REPll(n) for( ll i = 1 ; i <= n ; i++ )

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    bool c = 0;
    for( int i = 0 ; i < s.size() ; i++ ) {
        if( s == t ) c = 1;
        s = s.back() + s.substr( 0 , s.size() - 1 );
    }
    if( c == 1 ) cout << "Yes";
	else cout << "No";
}
