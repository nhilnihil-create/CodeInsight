#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t min_value = 753;
    for (size_t i = 0; i < s.length() - 2; ++i) {
        auto diff = abs(stoi(s.substr(i, 3)) - 753);
        if (diff < min_value) min_value = diff;
    }
    cout << min_value << endl;
    return EXIT_SUCCESS;
}