#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    bool hasYellow = false;
    for (int i = 0; i < N; i++) {
        char S; cin >> S;
        if (S == 'Y') {
            hasYellow = true;
        }
    }
    if (hasYellow) {
        cout << "Four" << endl;
    } else {
        cout << "Three" << endl;
    }
}
