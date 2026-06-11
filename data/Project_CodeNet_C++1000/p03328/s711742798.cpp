#include <bits/stdc++.h>
using namespace std;  

int main() {
    int a, b, ans;
    
    cin >> a >> b;
    ans = 0;
    for ( int i = 1; i < b-a; i++ ) {
        ans+=i;
    }
    
    cout << ans - a << endl;
    return (0);
}
