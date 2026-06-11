#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int x = N;
    while (x >= 0) {
        if (x % 4 == 0) {
            cout << "Yes" << endl;
            return 0;
        };
        x -= 7;
    }
    cout << "No" << endl;
    return 0;
}