#include <bits/stdc++.h>
using namespace std;  

int main() {
    int d, n, m, c;
    int i;
    
    cin >> d >> n;
    if ( d == 0 ) {
        m = 1;
    } else if ( d == 1 ) {
        m = 100;
    } else {
        m = 10000;
    }
    
    c = 0;
    i = 0;
    while (c < n) {
        i++;
        
        if ( i % m == 0 && i % (m*100) != 0 ) {
            c++;
        }
    }
    
    cout << i << endl;
    
    return (0);
}