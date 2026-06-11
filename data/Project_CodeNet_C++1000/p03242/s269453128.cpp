#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (auto ch : s) {
        if (ch == '1') cout << 9;
        else cout << 1;
    }
    cout << endl;
    return 0;
}
