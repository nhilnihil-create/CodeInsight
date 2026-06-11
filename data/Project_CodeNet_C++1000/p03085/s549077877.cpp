#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    cin >> c;
    char t;
    if (c == 'A') {
        t = 'T';
    }
    else if (c == 'T') {
        t = 'A';
    }
    else if (c == 'C') {
        t = 'G';
    }
    else if (c == 'G') {
        t = 'C';
    }

    cout << t << endl;
}