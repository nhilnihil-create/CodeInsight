#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B,C;
    
    cin >> A >> B >> C;
    if(A == B) {
        cout << C << "\n";
    } else {
        if(B == C) {
            cout << A << "\n";
        } else {
            cout << B << "\n";
        }
    }
    return 0;
}
