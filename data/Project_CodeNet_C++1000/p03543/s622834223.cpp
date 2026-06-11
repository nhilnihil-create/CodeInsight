#include <bits/stdc++.h>
using namespace std;

int main() {
    char N[4];
    cin >> N;

    if (N[0] == N[1] && N[1] == N[2]) {
        cout << "Yes" << endl;
    }
    else if (N[1] == N[2] && N[2] == N[3]) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}