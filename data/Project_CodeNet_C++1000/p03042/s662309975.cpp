#include <iostream>
#include <string>

using namespace std;

int main() {

    string s; cin >> s;
    string a = s.substr(0, 2), b = s.substr(2, 2);
    bool a_year = a > "12" || a == "00";
    bool b_year = b > "12" || b == "00";
    if ((a_year && b_year)) {
        cout << "NA\n";
    } else if (a_year) {
        cout << "YYMM\n";
    } else if (b_year) {
        cout << "MMYY\n";
    } else {
        cout << "AMBIGUOUS\n";
    }
}