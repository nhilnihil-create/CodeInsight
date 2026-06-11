#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    if(B - A + 1 < 2*K) {
        for(int i = 0; i < B - A + 1; i++) {
            cout << A + i << endl;
        }
        return 0;
    }

    for(int i = 0; i < K; i++) {
        cout << A + i << endl;
    }
    for(int i = 0; i < K; i++) {
        cout << B - K + 1 + i << endl;
    }

    return 0;
}