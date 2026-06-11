#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    
    if (a % b == 0) {
        cout << -1 << '\n';
    } else {
        cout << a << '\n';
    }
    
    return 0;
}