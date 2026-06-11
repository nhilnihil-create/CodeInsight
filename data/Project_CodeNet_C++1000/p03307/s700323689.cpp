#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15); 
    int n;
    cin >> n;
    if (n % 2 == 0) cout << n << endl; 
    else cout << 2 * n << endl; 
    return 0; 
}