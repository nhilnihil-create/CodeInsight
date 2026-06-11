#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int A, B;
    cin >> A >> B;

    if (A <= 8) {
        if (B <= 8) {
            cout << "Yay!" << endl;
        } else {
            cout << ":(" << endl;
        }
    } else {
        cout << ":(" << endl;
    }
    
    return 0;
}