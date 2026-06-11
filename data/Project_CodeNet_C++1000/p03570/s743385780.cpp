#include <iostream>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 2e5;
int dp[1 + MAX_N];
char s[1 + MAX_N];
int bin[1 + MAX_N];
map<int, int> f;

const int SIGMA = 'z' - 'a' + 1;

int main() {
    cin >> ( s + 1 );

    int n = strlen( s + 1 );

    for ( int i = 1; i <= n; i ++ )
        bin[i] = ( 1 << ( s[i] - 'a' ) );

    f[0] = 1;
    int sm = 0;
    for ( int i = 1; i <= n; i ++ ) {
        sm ^= bin[i];
        //cout << s[i] << ' ' << sm << ' ' << f[sm];

        if ( f[sm] )
            dp[i] = f[sm];
        else
            dp[i] = i;
        for ( int j = 0; j < SIGMA; j ++ ) {
                int smp = sm ^ ( 1 << j );
                if ( f[smp] )
                    dp[i] = min( dp[i], f[smp] );
            }

        //cout << ' ' << dp[i] << ' ' << f[1] << endl;
        if ( !f[sm] || dp[i] + 1 < f[sm] )
            f[sm] = dp[i] + 1;
    }
    //cout << SIGMA << endl;
    cout << dp[n];

    return 0;
}
