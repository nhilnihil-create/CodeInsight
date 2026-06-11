#include <bits/stdc++.h>
using namespace std;
int main() {
    int D;
    cin >> D;

    switch (D) {
    case 25:
        cout << "Christmas" << endl;
        break;
    case 24:
        cout << "Christmas"
             << " "
             << "Eve" << endl;
        break;
    case 23:
        cout << "Christmas"
             << " "
             << "Eve"
             << " "
             << "Eve" << endl;
        break;
    case 22: cout << "Christmas"
                  << " "
                  << "Eve"
                  << " "
                  << "Eve"
                  << " "
                  << "Eve" << endl;
    default:
        break;
    }
    return 0;
}
