#include <bits/stdc++.h>

using namespace std;

int main (void) {
    string S;
    long long K;
    cin >> S >> K;

    bool found = false;
    for ( int i=0; i<K; i++ ) {
        if ( S.at(i) != '1' ) {
            cout << S.at(i) << endl;
            found = true;
            break;
        }
    }
    if ( !found )
        cout << '1' << endl;

    return 0;
}
