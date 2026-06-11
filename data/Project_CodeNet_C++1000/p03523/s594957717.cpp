#include <iostream>
#include <regex>
using namespace std;

int main() {
    string s;
    cin >> s;
    regex checker("A?KIHA?BA?RA?");
    if (regex_match(s, checker)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}