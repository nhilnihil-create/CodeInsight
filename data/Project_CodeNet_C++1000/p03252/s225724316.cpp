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
#define rep2(n) for( int j = 0 ; j < n ; j++ )
#define REP2(n) for( int j = 1 ; j <= n ; j++ )
#define repll2(n) for( ll j = 0 ; j < n ; j++ )
#define REPll2(n) for( ll j = 1 ; j <= n ; j++ )

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s , t;
    cin >> s >> t;
    int n = s.length();
    int a[26] = {} , b[26] = {};
    bool y = true;
    for( int i = 0 ; i < n ; i++ ) {
        a[s[i] - 'a']++;
		b[t[i] - 'a']++;
        if( a[s[i] - 'a'] != b[t[i] - 'a'] ) {
            y = false;
            break;
        }
    }
    if( y ) cout << "Yes";
    else cout << "No";
}
