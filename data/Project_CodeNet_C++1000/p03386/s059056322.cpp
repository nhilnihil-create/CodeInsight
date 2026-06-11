#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int64_t A, B, K;
    cin >> A >> B >> K;
    int64_t e_a = min(B+1, A+K);
    for(int i=A; i < e_a; i++) {
        cout << i << endl;
    }

    int64_t b_s = B-K + 1;
        for (int i=b_s; i <= B; i++) {
            if (e_a <= i) {
                cout << i << endl;
            }
        }

    return 0;
}