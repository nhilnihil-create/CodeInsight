#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    for (int i = 0; i < 7; i++) {
        string a = S.substr(0, i), b = S.substr(S.length() - (7 - i), 7 - i);
        if (a + b == "keyence") {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
