#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

long long MOD = 1000000007;

int popcount( int a ) {
    int ret = 0;
    for ( int i = 0; i < 32; i++ ) {
        if ( a & ( 1 << i  ) ) { ret++; } 
    }
    return ret;
}

int main() {
    
    string S;
    cin >> S;
    
    vector<int> hash(S.length());
    
    for ( int i = 0; i < S.length(); i++ ) {
        if ( !i ) { hash[i] = ( 1 << (S[i]-'a' ) ); }
        else { hash[i] = hash[i-1] ^ ( 1 << (S[i]-'a') ); }
    }
    
    
    vector<int> dp( 1<<26 );
    for ( int i = 0; i < (1<<26); i++ ) {
        dp[i] = INT_MAX-1;
    }
    
    
    
    for ( int i = 0; i < S.length(); i++ ) {
        if ( popcount( hash[i] ) <= 1 ) {
            dp[hash[i]] = 1; 
            continue;
        }
        
        for ( int j = 0; j < 26; j++ ) {            
            dp[hash[i]] = min( dp[hash[i]], dp[ hash[i] ^ ( 1 << j ) ] + 1 );
        } 
    }
    
    cout << dp[hash[S.length()-1]] << endl;
    
    /* N^2 */    
    // vector<int> opt(S.length());
    // fill( opt.begin(), opt.end(), INT_MAX );
    // opt[0] = 1;
    
    // for ( int i = 1; i < S.length(); i++ ) {
        // if ( popcount( hash[i] ) <= 1 ) { opt[i] = 1; continue; }
        
        // for ( int j = 0; j < i; j++ ) {
            // if ( popcount( hash[i] ^ hash[j] ) <= 1 ) {
                // opt[i] = min( opt[i], opt[j] + 1 );
            // }
            // opt[i] = min( opt[i], opt[i-1]+1 );
        // }
    // }
    
    // cout << opt[S.length()-1] << endl;
    
    /* for debug */
    // for ( auto& a : hash ) {
        // string str;
        // for ( int i = 0; i < 26; i++ ) {
            // if ( a & ( 1 << i ) ) { str += "1"; }
            // else { str += "0"; }
        // }
        // cout << str << endl;
    // }
    
    return 0;
}