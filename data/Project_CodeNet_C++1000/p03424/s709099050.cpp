#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, type;
    cin >> N;

    int i = 0;
    while (i < N) {
        string s;
        cin >> s;
        if (s == "Y") {
            cout << "Four" << endl;
            break;
        }
        i++;
    }

    if (i == N) {
        cout << "Three" << endl;
    }
}
