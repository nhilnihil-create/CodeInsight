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

int main() {
    
    int A[3] = {0};
    string S;
    cin >> S;
    
    if ( S.length() == 1 ) {
        cout << "YES" << endl;
    }
    else if ( S.length() == 2 ) {
        cout << ( S[0] == S[1] ? "NO" : "YES" ) << endl;
    }
    else {            
        for ( int i = 0; i < S.length(); i++ ) {
            A[S[i] - 'a']++;
        }
        bool ans = abs(A[0]-A[1]) <= 1 && abs(A[1]-A[2]) <= 1 && abs(A[0]-A[2]) <= 1;
        cout << ( ans ? "YES" : "NO" ) << endl;
    }
    return 0;
}