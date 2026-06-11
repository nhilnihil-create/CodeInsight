#include<iostream>
using namespace std;

int main() {
    int A, B, K; cin >> A >> B >> K;
    for (int i = A; i <= B; i++) {
        if (A + K - 1 >= i || B - K + 1 <= i) {
            cout << i << endl;
        }
    }
}
