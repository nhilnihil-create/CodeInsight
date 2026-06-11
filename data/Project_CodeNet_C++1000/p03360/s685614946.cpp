#include <bits/stdc++.h>
using namespace std;

int main() {

    int A, B, C, K;

    cin >> A >> B >> C >> K;

    if (A >= B && A >= C) {
        cout << (A * pow(2, K)) + B + C << endl;
    }

    else if (B >= A && B >= C) {
        cout << A + (B * pow(2, K)) + C << endl;
    }

    else if (C >= B && C >= A) {
        cout << A + B + (C * pow(2, K)) << endl;
    }
}