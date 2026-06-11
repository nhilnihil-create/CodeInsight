#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int price = 700;
    for (const auto& v : s) {
        if (v == 'o') price += 100;
    }
    cout << price << endl;
    return EXIT_SUCCESS;
}