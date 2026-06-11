#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s; cin >> s;
    int zero = 0, ichi = 0;
    for (auto c : s) {
        if (c == '0') ++zero;
        else ++ichi;
    }
    cout << min(zero, ichi) * 2 << endl;
}