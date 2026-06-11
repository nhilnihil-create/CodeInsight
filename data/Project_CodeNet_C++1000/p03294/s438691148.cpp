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
    int n , c = 0;
    cin >> n;
    int a[n];
    rep(n) {
	    cin >> a[n];
	    c += a[n];
	}
	cout << c - n;
}
