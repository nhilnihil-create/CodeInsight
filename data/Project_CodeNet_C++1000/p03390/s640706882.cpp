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
    
    int Q;
    cin >> Q;
    vector<long long> A(Q);
    for ( int i = 0; i < Q; i++ ) {
        long long a,b,c,d;
        cin >> a >> b;
        c = a*b-1;
        d = static_cast<long long>(sqrt(c));

        long long x = max( d-2, 1LL );
        for ( ; x <= c/x ; x++ ) {}
        x--;
        long long ans = x*2;

        if ( ans == 0 ) { A[i] = 0; continue; }

        if ( x == c/x ) { ans--; }

        if ( x >= a ) { ans--; }
        if ( x >= b ) { ans--; }

        A[i] = ans;

    }
    for ( int i = 0; i < Q; i++ ) {
        cout << A[i] << endl;
    }

    return 0;
}