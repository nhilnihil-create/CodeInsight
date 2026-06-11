#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, f;
    string S;
    f = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S;
        if (S == "Y" && f == 0) {
            cout << "Four" << endl;
            f++;
        }
    }

    if (f == 0) {
        cout << "Three" << endl;
    }

}
