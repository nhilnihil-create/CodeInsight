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
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    if ( s.length() < t.length() ) {
        cout << "UNRESTORABLE";
        return 0;
    }
    int c = (int)(s.length() - t.length() );
    for ( int i = c ; i >= 0 ; i-- ) {
        bool y = 0;
        for ( int j = 0 ; j < t.length() ; j++ ) if ( s[j + i] != '?' && s[j + i] != t[j] ) y = 1;
        if ( y == 0 ) {
            for ( int j = 0 ; j < t.length() ; j++ ) s[j + i] = t[j];
            for ( int j = 0 ; j < s.length() ; j++ ) if ( s[j] == '?' ) s[j] = 'a';
            cout << s;
            return 0;
        }
    }
    cout << "UNRESTORABLE";
}
