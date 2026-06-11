#include <bits/stdc++.h>
using namespace std;  

int main(){
    string s;
    bool sma;
    int c_pos;
    
    cin >> s;
    if ( s[0] == 'A' ) {    
        c_pos = -1;
        
        for ( int i = 2; i < s.size()-1; i++ ) {
            if ( s[i] == 'C' ) {
                c_pos = i;
            }
        }
        if ( c_pos == -1 ) {
            cout << "WA\n";
        } else {
            sma = 1;
            for ( int i = 1; i < s.size(); i++ ) {
                if ( i != c_pos && (s[i] < 'a' || s[i] > 'z') ) {
                    sma = 0;
                }
            }
            cout << ( sma ? "AC\n" : "WA\n" );
        }
    } else {
        cout << "WA\n";
    }
    
    return (0);
}