#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll D,N;
    cin >> D >> N;
    
    if ( N != 100 ){
        if ( D == 0 ) cout << N << endl;
        else if ( D == 1 ) cout << 100 * N << endl;
        else cout << 10000 * N << endl;
    } else {
        if ( D == 0 ) cout << 101 << endl;
        else if ( D == 1 ) cout << 10100 << endl;
        else cout << 1010000 << endl;
    }
    
    return 0;
}
