#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string res = "No";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (N == i * 4 + j * 7) res = "Yes";
        }
    }

    cout << res << endl;
}