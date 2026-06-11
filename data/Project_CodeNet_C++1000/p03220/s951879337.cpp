#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, pos;
    double t, a, h[1000];
    
    cin >> n;
    cin >> t >> a;
    for ( int i = 0; i < n; i++ ) {
        cin >> h[i];
    }
    
    pos = 0;
    h[0] = t - h[0] * 0.006;
    for ( int i = 1; i < n; i++ ) {
        h[i] = t - h[i] * 0.006;
        
        if ( abs(h[i] - a) < abs(h[pos] - a) ) {
            pos = i;
        }
    }
    
    cout << pos + 1 << endl;
    
    return (0);
}
