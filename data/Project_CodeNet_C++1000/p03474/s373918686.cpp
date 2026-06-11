#include<iostream>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    string S; cin >> S;
    bool can_match = true;
    for (int i = 0; i < a + b + 1; i++) {
        if (i < a) {
            if (S[i] >= 48 && S[i] <= 57) {
                continue;
            } else {
                can_match = false;
            }
        } else if (i == a) {
            if (S[i] == '-') {
                continue;
            } else {
                can_match = false;
            }
        } else {
            if (S[i] >= 48 && S[i] <= 57) {
                continue;
            } else {
                can_match = false;
            }
        }
    }
    if (can_match) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
