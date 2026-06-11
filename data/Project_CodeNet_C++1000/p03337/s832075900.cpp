#include <bits/stdc++.h>
using namespace std;

int main() {

    int A, B;

    cin >> A >> B;

    int sum, sub, mult;

    sum = A + B;

    sub = A - B;

    mult = A * B;

    if (sum >= sub && sum >= mult) {
        cout << sum << endl;
    }
    else if (sub >= sum && sub >= mult) {
        cout << sub << endl;
    }
    else {
        cout << mult << endl;
    }
    
}