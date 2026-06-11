#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <set>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    set <string> a;
    for( int i = 1 ; i <= k ; i++ ) {
        for( int j = 0 ; j < s.length() ; j++ ) {
            if( j + i <= s.length() ) a.insert( s.substr( j , i ) );
        }
    }
    auto j = a.begin();
	for ( int i = 0 ; i < k - 1 ; i++ ) j++;
	cout << *j;
}