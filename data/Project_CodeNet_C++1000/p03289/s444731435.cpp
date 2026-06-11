#include <bits/stdc++.h>

using namespace std;

int main (void) {
    string S;
    cin >> S;

    if ( S.at(0) != 'A' ) {
        cout << "WA" << endl;
        return 0;
    }

    int C_cnt = 0;
    for ( int i=2; i<S.size()-1; i++ ) {
        if ( S.at(i) == 'C' )
            C_cnt++;
    }
    if ( C_cnt != 1 ) {
        cout << "WA" << endl;
        return 0;
    }

    for ( int i=1; i<S.size(); i++ ) {
        if ( S.at(i) != 'C' && isupper(S.at(i)) ) {
            cout << "WA" << endl;
            return 0;
        }
    }

    cout << "AC" << endl;
    return 0;
}
