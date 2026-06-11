#include <bits/stdc++.h>
using namespace std;
int main () {
    
    long a, b, k;
    
    cin >> a >> b >> k;
    
    for (int i = 1; i <= k; i++)
        if (i % 2 != 0)
            if (a % 2 == 0) {a /= 2; b += a;}
            else {a -= 1; a /= 2; b += a;}
        else
            if (b % 2 == 0) {b /= 2; a += b;}
            else {b -= 1; b /= 2; a += b;}
    
    cout << a << " " << b << endl;
    
    return 0;
}