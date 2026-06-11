#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, a, ma, mi;
    cin >> n;
    ma = 0;
    mi = INT_MAX;
    
    for ( int i = 0; i < n; i++ ) {
        cin >> a;
        ma = max(ma, a);
        mi = min(mi, a);
    }
    
    cout << ma - mi << endl;
    
    return (0);
}
