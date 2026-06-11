#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i; i < A.size(); i++) cin >> A.at(i);

    int counter = 0;
    bool dividable = true;
    while (dividable) {
        for (int i = 0; i < A.size(); i++) {
            int a = A[i];
            if (a % 2 == 0) {
                a /= 2;
                A[i] = a;
            } else {
                dividable = false;
                break;
            }
        }
        if (dividable) counter++;
    }

    cout << counter << endl;
}