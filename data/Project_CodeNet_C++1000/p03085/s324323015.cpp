#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string b, c;
    cin >> b;
    if (b == "A") {
        c = "T";
    } else if (b == "T") {
        c = "A";
    } else if (b == "C") {
        c = "G";
    } else if (b == "G") {
        c = "C";
    }
    cout << c << endl;
    return 0;
}
