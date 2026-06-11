#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, b, k;
    stack<int> vec;
    cin >> a >> b >> k;
    
    for ( int i = 1; i <= min(a, b); i++ ) {
        if ( a % i == 0 && b % i == 0 ) {
            vec.push(i);
        }
    }
    
    for ( int i = 1; i < k; i++ ) {
        vec.pop();
    }
    cout << vec.top() << endl;
    return (0);
}