#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> b(10);
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        b.at(a) = true;
    }    
    cout << (b[1] && b[9] && b[7] && b[4] ? "YES" : "NO") << endl;
}