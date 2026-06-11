#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MOD ( long ) ( 1e9 + 7 ) 

int main() {
	 string s;
	 cin >> s;
    vector < long [ 4 ]> dp (s.size () + 1 );
    dp [ 0 ] [ 0 ] = 1 ;
     for ( int i = 1 ; i <= s.size (); i ++) {
         for ( int j = 0 ; j <= 3 ; j ++) {
            dp [i] [j] = dp [i- 1 ] [j];
             if (s [i- 1 ] == '?' )
                dp [i] [j] *= 3 ;
            dp [i] [j]%= MOD;
        }
        if (s [i- 1 ]!= '?' )
            dp [i] [s [i- 1 ] + 1 - 'A' ] += dp [i- 1 ] [s [i- 1 ] - 'A' ];
          else {
             for ( int j = 1 ; j <= 3 ; j ++) {
                dp [i] [j] += dp [i- 1 ] [j- 1 ];
               dp [i] [j]%= MOD;
            }
        }
    }
    cout << dp [s.size ()] [ 3 ]% MOD;
	return 0;
}