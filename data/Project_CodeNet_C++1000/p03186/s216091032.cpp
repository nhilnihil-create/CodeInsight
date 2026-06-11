#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    if(B >= C) {
        cout << C+B << endl;
    }
    else {
        if(A+B >= C-1) {
            cout << C+B << endl;
        }
        else {
            cout << A+B+B+1 << endl;
        }
    }
}