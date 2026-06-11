#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool ret = s[0] == 'A';

    int count = 0;
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == 'C')count++;
    }
    if (count != 1)ret = false;

    count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i]))count++;
    }
    if (count != s.size() - 2)ret = false;

    cout << (ret ? "AC" : "WA") << endl;
    return 0;
}